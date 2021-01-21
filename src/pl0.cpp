#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

int yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    return -1;
}

int yyparse();

int main(int argc, char* argv[]) {
    extern FILE *yyin;

    // check whether the user added a file to compile
    if (argc < 2) {
        printf("Missing argument: File to compile");
        return 1;
    }

    // get passed filepath and open the file
    char *filePath = argv[1];
    yyin = fopen(filePath, "r");

    yyparse();
    return 0;  // wegen return value vorgaben noch auf anforderungsblatt schauen
}
