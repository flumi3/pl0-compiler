# makefile fuer PL/0-Compiler
# 
#
OBJECTS=main.o parser.o symtab.o lex.yy.o

# Executable
pl-0: $(OBJECTS) *.y *.l
	$(CPP) $(OBJECTS) -g -o pl-0

# YACC-Parser
parser.o:	pl0-y-parser.y
	yacc pl0-y-parser.y -d -b parser -o parser.tab.cpp
	$(CPP) -g -c parser.tab.cpp -o parser.o

#Scanner
lex.yy.o: pl0-scanner.l
	lex -o lex.yy.cpp pl0-scanner.l
	$(CPP) -g -c lex.yy.cpp

# Symboltabelle
symtab.o: pl0-symtab.cpp pl0-symtab.hpp
	$(CPP) -g -c pl0-symtab.cpp -o symtab.o

# Hauptprogramm
main.o: pl0.cpp
	$(CPP) -g -c pl0.cpp -o main.o

clean:
	rm -f $(OBJECTS) parser.tab.* lex.yy.* pl-0

clean-all: clean
	rm -f pl-0
