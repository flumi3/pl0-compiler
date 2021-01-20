%{
    #include <stdio.h>
    #include <vector>
    #include "pl0-symtab.hpp"
    #include "optree.h"
    #include "ast.hpp"

    int yylex();
    int yyerror(char *s);

    symtab st;
    int global_proc_nr = 0;
    int local_var_nr = 0;

    /* 
    list that holds all procedures and their nodes. 
    
    Example:
    procedure f;
        a := 1;

    ...

    procedure g;
        begin
            call f;
            ! 3;
        end;

    Then the list holds 3 procedures (vectors):
        - Main procedure (always at index 0)
        - Procedure f on index 1 containing its AssignNode
        - Procedure g on index 2 containing its CallNode and WriteNode
    */ 
    vector<vector<Node>> procedure_list;
%}

%union {
    Ast *ast; 
    int num;
    char txt[20];
    opTree *tree;
    vector<Node*> *statements;
}

%token t_const t_var t_procedure t_call t_begin t_end t_if t_then t_while t_do t_odd    /* keywords */
%token t_equals t_hashtag t_lt t_lteq t_gt t_gteq   /* condition operators */
%token t_plus t_minus t_mult t_div  /* arithmetic operators */
%token t_assign t_qMark t_eMark     /* := ? ! */
%token t_dot t_comma t_semicolon t_br_open t_br_close   /* . , ; ( ) */
%token t_number t_ident

%type <tree> factor term expression condition
%type <num> t_number
%type <txt> t_ident
%type <statements> block block_declaration statement statements

%%
program:
    block t_dot {
        // Ast ast;
        // ast.nodes = $1
    }
    ;

block:
    block_declaration statement
    ;

block_declaration:
    { st.level_up(); }
    constant_declaration variable_declaration procedure_declaration
    { st.level_down(); }
    ;

constant_declaration:
    t_const constants t_semicolon
    | /* empty */
    ;

constants:
    t_ident t_equals t_number {
        int rt = st.insert($1, st_const, $3);
        if (rt != 0) {
            yyerror((char*)"Error: Could not insert constant!");
        }
    }
    | constants t_comma t_ident t_equals t_number {
        int rt = st.insert($3, st_const, $5);
        if (rt != 0) {
            yyerror((char*)"Error: Could not insert constant!");
        }
    }
    ;

variable_declaration:
    t_var variables t_semicolon
    | /* empty */
    ;

variables:
    t_ident {
        int rt = st.insert($1, st_var, ++local_var_nr);
        if (rt != 0) {
            yyerror((char*)"Error: Could not insert variable!");
        } 
    }
    | variables t_comma t_ident {
        int rt = st.insert($3, st_var, ++local_var_nr);
        if (rt != 0) {
            yyerror((char*)"Error: Could not insert variable!");
        }
    }
    ;

procedure_declaration:
    procedures
    | /* empty */
    ;

procedures:
    t_procedure t_ident t_semicolon block t_semicolon {
        int rt = st.insert($2, st_proc, ++global_proc_nr);
        if (rt != 0) {
            yyerror((char*)"Error: Could not insert procedure!");
        } else {            
            // add a new procedure to vector of procedures
            // vector<Node> statementList = $4;
            // procedure_list.push_back(statementList); 
        }
    } 
    | procedures t_procedure t_ident t_semicolon block t_semicolon {
        int rt = st.insert($3, st_proc, ++global_proc_nr);
        if (rt != 0) {
            yyerror((char*)"Error: Could not insert procedure!");
        } else {
            // add new procedure to vector of procedures
            // vector<Node> statementList = $5;
            // procedure_list.push_back(statementList);
        }
    }
    ;

statement:
    t_ident t_assign expression {
        // vector<Node> statementList;
        // AssignNode newNode = AssignNode(scope??, level??, $3);
        // statementList.push_back(newNode);
        // $$ = statementList;
        // Muss hier iwas mit lookup oder dem symtab rein? 
    }
    | t_call t_ident {
        int stl, sto;
        int rt = st.lookup($2, st_proc, stl, global_proc_nr);
        if (rt == -1) {
            yyerror((char*)"Error: Wrong type!");
        } else if (rt == -2) {
            yyerror((char*)"Error: Not found!");
        } else {
            /* 
            wie funktioniert ein call aufruf????? 
            Sollte die procedure im aktuellen lvl des symtab enthalten sein, wird die procedure number der proc
            in der global_proc_nr gespeichert (zeiger shit). Alle procedures und ihre knoten sind in der procedure
            list enthalten. Die procNr, die im CallNode gespeichert ist, stellt auch gleichzeitig den index dar,
            an welchem sich die procedure in der procedure list befindet. Das heißt wir können über die procNr
            auf alle Knoten dieser procedure zugreifen.
            */ 
            // int proc_index = global_proc_nr;
            // CallNode newNode = CallNode(proc_index);
            // vector<Node> statementList;
            // statementList.push_back(newNode);  
            // $$ = statementList;
        }
    }
    | t_qMark t_ident {
        // vector<Node> statementList;
        // int input;
        // cin >> input;
        // brauch man hier einen lookup ob der ident in der symtab existiert?
        // st.insert($2, ) ??  
    }
    | t_eMark expression { 
        // vector<Node> statementList;
        // WriteNode newNode = WriteNode($2);
        // statementList.push_back(newNode);
        // $$ = statementList;
    }
    | t_begin statements t_end { 
        // statements muss ein vector an nodes sein oder?
        // $$ = $2;
    }
    | t_if condition t_then statement { 
        /* jmp_f node erstellen, dann kommen die statement nodes zwischen rein, und zum abschluss ein nop node.
        der jmp_f node muss auf den nop node zeigen, da dort hingesprungen wird, wenn die condition nicht wahr ist */
        // vector<Node> existingStatements = $3;
        // vector<Node> statementList;
        // ConditionNode newNode = ConditionNode($2);
        // statementList.push_back(newNode);
        // statementList.insert(end(statementList), begin(existingStatements), end(existingStatements));
        // $$ = statementList;
    }
    | t_while condition t_do statement { 
        /*  jmpf node erstellen, statement sind die nodes der schleife, nach end muss dann noch ein normaler jmp node
        der dann auf den jmp_f node vom anfang zeigt. der jmpf node vom anfang muss auf den node nach dem jmp node
        zeigen, siehe folie 406*/
        // vector<Node> statementList;
        // ConditionNode newNode = ConditionNode($2);
        // statementList.push_back(newNode);
        // vector<Node> existingStatements = $4;
        // statementList.insert(end(statementList), begin(existingStatements), end(existingStatements));
        // $$ = statementList;
    }
    | /* empty */
    ;

statements:
    statement {
        $$ = $1; // $1 muss schon ein existierender vector an nodes sein
    }
    | statements t_semicolon statement {
        // statements muss der vector sein und statement der neue node, d.h. hier dann den node zum vector hinzufügen?
        // Node newNode = $3;
        // vector<Node> statementList = $1;
        // statementList.push_back(newNode);
        // $$ = statementList;
    }
    | /* empty */
    ;

condition:
    t_odd expression                    { $$ = new opTree(opTreeEntry(treeEntryType::odd), $2); }
    | expression t_equals expression    { $$ = new opTree(opTreeEntry(treeEntryType::equals), $1, $3); }
    | expression t_hashtag expression   { $$ = new opTree(opTreeEntry(treeEntryType::hashtag), $1, $3); }
    | expression t_lt expression        { $$ = new opTree(opTreeEntry(treeEntryType::lessThan), $1, $3); }
    | expression t_lteq expression      { $$ = new opTree(opTreeEntry(treeEntryType::lessThanEqual), $1, $3); }
    | expression t_gt expression        { $$ = new opTree(opTreeEntry(treeEntryType::greaterThan), $1, $3); }
    | expression t_gteq expression      { $$ = new opTree(opTreeEntry(treeEntryType::greaterThanEqual), $1, $3); }
    ;

expression:
    term                        { $$ = $1; } 
    | t_plus term               { $$ = new opTree(opTreeEntry(treeEntryType::plus), $2); }
    | t_minus term              { $$ = new opTree(opTreeEntry(treeEntryType::minus), $2); }
    | expression t_plus term    { $$ = new opTree(opTreeEntry(treeEntryType::plus), $1, $3); }
    | expression t_minus term   { $$ = new opTree(opTreeEntry(treeEntryType::minus), $1, $3); }
    ;

term:
    factor                  { $$ = $1; }
    | factor t_mult term    { $$ = new opTree(opTreeEntry(treeEntryType::mult), $1, $3); }
    | factor t_div term     { $$ = new opTree(opTreeEntry(treeEntryType::division), $1, $3); }
    ;

factor:
    t_ident {
        int stl, sto;
        int rt = st.lookup($1, st_var|st_const, stl, local_var_nr);
        if (rt == -1) {
            yyerror((char*)"Error: Wrong type!");
        } else if (rt == -2) {
            yyerror((char*)"Error: Not found!");
        } else {
            $$ = new opTree(opTreeEntry(treeEntryType::identifier));
        }
    }
    | t_number                          { $$ = new opTree(opTreeEntry(treeEntryType::number, $1)); }
    | t_br_open expression t_br_close   { $$ = $2; }
    ;

%%
