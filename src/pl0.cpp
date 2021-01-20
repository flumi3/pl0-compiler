#include <stdio.h>

int yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    return -1;
}

int yyparse();

int main() {
    yyparse();
    return 0;  // wegen return value vorgaben noch auf anforderungsblatt schauen
}
