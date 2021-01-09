# makefile fuer PL/0-Compiler
# 
#
OBJECTS=main.o parser.o lex.yy.o symtab.o ast.o interpreter.o optimierer.o

# Executable
pl-0: $(OBJECTS) *.y *.l
	$(CPP) $(OBJECTS) -o pl-0

# YACC-Parser
parser.o:	pl0-y-parser.y
	yacc pl0-y-parser.y -d -b parser -o parser.tab.cpp
	$(CPP) -c parser.tab.cpp -o parser.o

# RD-Parser
# parser.o:	pl0-rd-parser.cpp
#	$(CPP) -c pl0-rd-parser.cpp -o parser.o

#Scanner
lex.yy.o: pl0-scanner.l
	lex -o lex.yy.cpp pl0-scanner.l
	$(CPP) -c lex.yy.cpp

# Symboltabelle
symtab.o: pl0-symtab.cpp pl0-symtab.hpp
	$(CPP) -c pl0-symtab.cpp -o symtab.o

# Zwischencode
# ast.o:	pl0-ast.cpp pl0-ast.hpp
# 	$(CPP) -c pl0-ast.cpp -o ast.o

# Interpreter
# interpreter.o: pl0-interpreter.cpp pl0-interpreter.hpp
# 	$(CPP) -c pl0-interpreter.cpp -o interpreter.o

# Optimierer
# optimierer.o: pl0-optimierer.cpp pl0-optimierer.hpp
# 	$(CPP) -c pl0-optimierer.cpp -o optimierer.o

# Hauptprogramm
main.o: pl0.cpp
	$(CPP) -c pl0.cpp -o main.o

clean:
	rm -f $(OBJECTS) parser.tab.* lex.yy.*

clean-all: clean
	rm -f pl-0
