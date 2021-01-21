# makefile fuer PL/0-Compiler
# 
#
OBJECTS=main.o parser.o lex.yy.o

# Executable
pl-0: $(OBJECTS) *.y *.l
	$(CPP) $(OBJECTS) -o pl-0

# YACC-Parser
parser.o:	pl0-y-parser.y
	yacc pl0-y-parser.y -d -b parser -o parser.tab.cpp
	$(CPP) -c parser.tab.cpp -o parser.o

#Scanner
lex.yy.o: pl0-scanner.l
	lex -o lex.yy.cpp pl0-scanner.l
	$(CPP) -c lex.yy.cpp

# Hauptprogramm
main.o: pl0.cpp
	$(CPP) -c pl0.cpp -o main.o

clean:
	rm -f $(OBJECTS) parser.tab.* lex.yy.*

clean-all: clean
	rm -f pl-0
