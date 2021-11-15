# pl0-compiler
Only contains scanner, parser and symbol table.  
When running this with a pl0 program, it will only perform a lexical, syntactic and semantic analysis on the pl0 program.  
Return code is 0 in case of successful parsing of the pl0 program.

### Requirements
- C++ Compiler
- Bison
- Flex

### Usage example
```shell
cd src  
export CPP=g++  
export CC=gcc  
make  
./pl-0 ./../pl0-programs/printPrimes  
echo $?
```

### Compile and analyse all pl0 programs
```shell
cd src  
sudo chmod u+x ./test.sh  
./test.sh
```
