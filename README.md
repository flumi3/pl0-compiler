# pl0-compiler
Only contains the scanner and the parser.  
When running this with a pl0 program, it will only perform a lexical and syntactic analysis on the pl0 program.  
Return code 0 in case of successful parsing of the pl0 program.

### Requirements
- C++ Compiler
- Bison
- Flex

### Usage example (Linux)
$ cd src  
$ export CPP=g++  
$ make  
$ ./pl-0 ./../pl0-programs/printPrimes  
$ echo $?  
