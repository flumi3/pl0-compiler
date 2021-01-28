#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int yyparse();

void yyerror(char const *s) {
    fprintf(stderr, "%s\n", s);
}

int main(int argc, char* argv[]) {
    extern FILE *yyin;

    // check whether the user added a file to compile
    if (argc < 2) {
        printf("Missing argument: File to compile");
        return 1;
    }

    char *userInput= argv[1];  // file path input from user (without .pl0 extension)
    char filePath[100];  // char array to hold the file path with the .pl0 extension
    strcpy(filePath, userInput);  // copy the user input into filePath
    strcat(filePath, ".pl0");  // add the .pl0 extension
    
    // open the file and pass it as input to the lexer 
    yyin = fopen(filePath, "r");

    return yyparse();
}
