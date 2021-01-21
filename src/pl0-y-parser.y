%{
    #include <stdio.h>
    #include <vector>

    int yylex();
    int yyerror(char *s);

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
%}

%union {
    int num;
    char txt[20];
}

%token t_const t_var t_procedure t_call t_begin t_end t_if t_then t_while t_do t_odd    /* keywords */
%token t_equals t_hashtag t_lt t_lteq t_gt t_gteq   /* condition operators */
%token t_plus t_minus t_mult t_div  /* arithmetic operators */
%token t_assign t_qMark t_eMark     /* := ? ! */
%token t_dot t_comma t_semicolon t_br_open t_br_close   /* . , ; ( ) */
%token t_number t_ident

%type <num> t_number
%type <txt> t_ident

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
    constant_declaration variable_declaration procedure_declaration
    ;

constant_declaration:
    t_const constants t_semicolon
    | /* empty */
    ;

constants:
    t_ident t_equals t_number
    | constants t_comma t_ident t_equals t_number
    ;

variable_declaration:
    t_var variables t_semicolon
    | /* empty */
    ;

variables:
    t_ident
    | variables t_comma t_ident
    ;

procedure_declaration:
    procedures
    | /* empty */
    ;

procedures:
    t_procedure t_ident t_semicolon block t_semicolon
    | procedures t_procedure t_ident t_semicolon block t_semicolon
    ;

statement:
    t_ident t_assign expression
    | t_call t_ident
    | t_qMark t_ident
    | t_eMark expression
    | t_begin statements t_end
    | t_if condition t_then statement
    | t_while condition t_do statement
    | /* empty */
    ;

statements:
    statement
    | statements t_semicolon statement
    | /* empty */
    ;

condition:
    t_odd expression
    | expression t_equals expression
    | expression t_hashtag expression
    | expression t_lt expression
    | expression t_lteq expression
    | expression t_gt expression
    | expression t_gteq expression
    ;

expression:
    term
    | t_plus term
    | t_minus term
    | expression t_plus term
    | expression t_minus term
    ;

term:
    factor
    | factor t_mult term
    | factor t_div term
    ;

factor:
    t_ident
    | t_number
    | t_br_open expression t_br_close
    ;

%%
