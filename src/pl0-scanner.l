%{
    #include "parser.tab.hpp" // include file that got generated from the parser by bison

    int yyerror(char *s);  // eventuell raus schmeißen
    int lineCounter = 0;
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
