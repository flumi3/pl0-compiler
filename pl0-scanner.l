%{
    #include "y.tab.h"

    int yyerror(char *s);
    int lineCounter = 0;

    enum {
        t_const, t_var, t_procedure, t_call, t_begin, t_end, t_if, t_then, t_while, t_do, t_odd, t_assign, 
        t_qMark, t_eMark, t_equals, t_hashtag, t_lt, t_lteq, t_gt, t_gteq, t_plus, t_minus, t_mult, 
        t_div, t_dot, t_comma, t_semicolon, t_br_open, t_br_close, t_integer, t_ident, t_number
    };
%}

%%
"CONST"|"const"             return t_const;
"VAR"|"var"                 return t_var;
"PROCEDURE"|"procedure"     return t_procedure;
"CALL"|"call"               return t_call;
"BEGIN"|"BEGIN"             return t_begin;
"END"|"end"                 return t_end;
"IF"|"if"                   return t_if;
"THEN"|"then"               return t_then;
"WHILE"|"while"             return t_while;
"DO"|"do"                   return t_do;
"ODD"|"odd"                 return t_odd;

":="        return t_assign;
"?"         return t_qMark;
"!"         return t_eMark;

"="         return t_equals;
"#"         return t_hashtag;
"<"         return t_lt;
"<="        return t_lteq;
">"         return t_gt;
">="        return t_gteq;

"+"         return t_plus;
"-"         return t_minus;
"*"         return t_mult;
"/"         return t_div;

"."         return t_dot;
","         return t_comma;
";"         return t_semicolon;
"("         return t_br_open;
")"         return t_br_close;

\d+                     { yylval.num = atoi(yytext); return t_number; }
[a-zA-Z][a-zA-Z0-9_]*   { strncpy(yylval.txt, yytext, 16); return t_ident; }
\n                      return ++lineCounter;
[ \t]+                  ; /* do nothing */
.                       yyerror("Syntax Error");
%%

int yywrap() {
    return 1;
}
