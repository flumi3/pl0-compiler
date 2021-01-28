%{
    #include "parser.tab.hpp" // include file that got generated from the parser by bison

    int yyerror(char const *s);
    void print_scan(char *s);  
    int lineCounter = 0;
    
    int print = 0;  // bool variable that tells whether to print the scanned text or not, 0 = yes, other = no
    void print_scan(char *s) {
        if (print == 0) {
            printf("\x1b[33mscan line[%d]: %s \x1b[0m \n", lineCounter, s);
        }
    }
%}

%option case-insensitive

%%
"CONST"         { print_scan(yytext); return t_const; }
"VAR"           { print_scan(yytext); return t_var; }
"PROCEDURE"     { print_scan(yytext); return t_procedure; }
"CALL"          { print_scan(yytext); return t_call; }
"BEGIN"         { print_scan(yytext); return t_begin; }
"END"           { print_scan(yytext); return t_end; }
"IF"            { print_scan(yytext); return t_if; }
"THEN"          { print_scan(yytext); return t_then; }
"WHILE"         { print_scan(yytext); return t_while; }
"DO"            { print_scan(yytext); return t_do; }
"ODD"           { print_scan(yytext); return t_odd; }

":="        { print_scan(yytext); return t_assign; }
"?"         { print_scan(yytext); return t_qMark; }
"!"         { print_scan(yytext); return t_eMark; }

"="         { print_scan(yytext); return t_equals; }
"#"         { print_scan(yytext); return t_hashtag; }
"<"         { print_scan(yytext); return t_lt; }
"<="        { print_scan(yytext); return t_lteq; }
">"         { print_scan(yytext); return t_gt; }
">="        { print_scan(yytext); return t_gteq; }

"+"         { print_scan(yytext); return t_plus; }
"-"         { print_scan(yytext); return t_minus; }
"*"         { print_scan(yytext); return t_mult; }
"/"         { print_scan(yytext); return t_div; }

"."         { print_scan(yytext); return t_dot; }
","         { print_scan(yytext); return t_comma; }
";"         { print_scan(yytext); return t_semicolon; }
"("         { print_scan(yytext); return t_br_open; }
")"         { print_scan(yytext); return t_br_close; }

[0-9]+                  { print_scan(yytext); yylval.num = atoi(yytext); return t_number; }
[a-zA-Z][a-zA-Z0-9_]*   { print_scan(yytext); strncpy(yylval.txt, yytext, 16); return t_ident; }
\n                      { print_scan((char*)"\\n"); lineCounter++; }
[ \t]+                  { ; /* do nothing */ }
.                       { printf("Syntax error on line %d", lineCounter); }
%%

int yywrap() {
    return 1;
}
