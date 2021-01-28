%{
    #include <stdio.h>
    #include "pl0-symtab.hpp"

    int yylex();
    int yyerror(char const *s);

    int global_proc_nr = 0;
    int local_var_nr = 0;
    symtab st;
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
    { st.level_up(); }
    block t_dot
    { st.level_down(); }
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
            yyerror((char*)"Error: Could not insert constant");
            return 1;
        }
    }
    | constants t_comma t_ident t_equals t_number {
        int rt = st.insert($3, st_const, $5);
        if (rt != 0) {
            yyerror((char*)"Error: Could not insert constant");
            return 1;
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
            return 1;
        } 
    }
    | variables t_comma t_ident {
        int rt = st.insert($3, st_var, ++local_var_nr);
        if (rt != 0) {
            yyerror((char*)"Error: Could not insert variable!");
            return 1;
        }
    }
    ;

procedure_declaration:
    procedures
    | /* empty */
    ;

procedures:
    t_procedure t_ident t_semicolon {
        int rt = st.insert($2, st_proc, ++global_proc_nr);
        if (rt != 0) {
            yyerror((char*)"Error: Could not insert procedure!");
        } else {
            st.level_up();
        }
    } block t_semicolon {
        st.level_down();
    }
    | procedures t_procedure t_ident t_semicolon {
        int rt = st.insert($3, st_proc, ++global_proc_nr);
        if (rt != 0) {
            yyerror((char*)"Error: Could not insert procedure!");
        } else {
            st.level_up();
        }
    } block t_semicolon {
        st.level_down();
    }
    ;

statement:
    t_ident t_assign expression
    | t_call t_ident {
        int stl, sto;
        int rt = st.lookup($2, st_proc, stl, global_proc_nr);
        if (rt == -1) {
            yyerror((char*)"Error: Wrong type!");
            return 1;
        } else if (rt == -2) {
            yyerror((char*)"Error: Not found!");
            return 1;
        }
    }
    | t_qMark t_ident
    | t_eMark expression
    | t_begin { st.level_up(); } statements t_end { st.level_down(); }
    | t_if condition t_then statement
    | t_while condition t_do statement
    | /* empty */
    ;

statements:
    statement
    | statements t_semicolon statement
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
