%{
    #include <stdio.h>
    #include "symbol_table/pl0-symtab.hpp"
    #include "operator_tree/optree.h"

    int yylex();
    int yyerror(char *s);

    symtab st;
    int global_proc_nr = 0;
    int local_var_nr = 0;
%}

%union {
    int num;
    opTree* tree;
    opTreeEntry entry;
    char* id;
}

%token t_const t_var t_procedure t_call t_begin t_end t_if t_then t_while t_do t_odd    /* keywords */
%token t_equals t_hashtag t_lt t_lteq t_gt t_gteq   /* condition operators */
%token t_plus t_minus t_mult t_div  /* arithmetic operators */
%token t_assign t_qMark t_eMark     /* := ? ! */
%token t_dot t_comma t_semicolon t_br_open t_br_close   /* . , ; ( ) */
%token t_number t_ident

%type <tree> factor term expression condition
%type <num> t_number
%type <id> t_ident

%%
program:
    block t_dot     {/* ast = $1; skript "methodenaufrufe in yacc" */}
    ;

block:
    block_declaration statement
    ;

block_declaration:  
    constant_declaration variable_declaration procedure_declaration
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
    t_procedure t_ident {
        int rt = st.insert($2, st_proc, ++global_proc_nr);
        if (rt != 0) {
            yyerror((char*)"Error: Could not insert procedure!");
        } else {
            // ast erzeugen -> 
        }
    } 
    t_semicolon block t_semicolon
    | procedures t_procedure t_ident t_semicolon block t_semicolon {
        int rt = st.insert($3, st_proc, ++global_proc_nr);
        if (rt != 0) {
            yyerror((char*)"Error: Could not insert procedure!");
        }
    }
    ;

statement:
    t_ident t_assign expression
    | t_call t_ident    {
        int stl, sto;
        int rt = st.lookup($2, st_proc, stl, global_proc_nr);
        if (rt == -1) {
            yyerror((char*)"Error: Wrong type!");
        } else if (rt == -2) {
            yyerror((char*)"Error: Not found!");
        } else {
            // hier muss noch was mit ast rein 
        }
    }
    | t_qMark t_ident
    | t_eMark expression                    { /* print das fertige ergebnis? */ }
    | t_begin {} statements t_end           { /* betreten und verlassen einer neuen ebene???? */ }
    | t_if condition t_then statement       { /* baum */ }
    | t_while condition t_do statement
    | /* empty */
    ;

statements:
    statement
    | statements t_semicolon statement
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
            $$ = new opTree(opTreeEntry(treeEntryType::identifier, $1));
        }
    }
    | t_number                          { $$ = new opTree(opTreeEntry(treeEntryType::number, $1)); }
    | t_br_open expression t_br_close   { $$ = $2; }
    ;

%%
#include "lex.yy.c"

int yyerror(char const *s) {
    printf(stderr, "%s\n", s);
    return -1;
}

int main() {
    yyparse();
}
