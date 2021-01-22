# pl0-compiler
Only contains the scanner and the parser.  
When running this with a pl0 program, it will only perform a lexical and syntactic analysis on the pl0 program.

### Requirements
- C++ Compiler
- Bison
- Flex

### Usage example (Linux)
$ cd src  
$ export CPP=g++  // specify compiler  
$ make  
$ ./pl-0 /some/where/test  // without .pl0 extension  
$ echo $?  // pl-0 return code  
