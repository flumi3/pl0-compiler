# pl0-compiler
Only contains the scanner and the parser.  
When running this with a pl0 program, it will only perform a lexical and syntactic analysis on the pl0 program.  
Return code 0 in case of successful parsing of the pl0 program.

### Requirements
- C++ Compiler
- Bison
- Flex

### Usage example
$ cd src  
$ export CPP=g++  
$ make  
$ ./pl-0 ./../pl0-programs/printPrimes  
$ echo $?  

### Compile and analyse all pl0 programs
$ cd src  
$ sudo chmod u+x ./test.sh  
$ ./test.sh  
