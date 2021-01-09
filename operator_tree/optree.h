#pragma once

#include <iostream>
#include "tree.hpp"
#include "string.h"

using namespace std;

enum treeEntryType {
	// arithmetic tokens
	plus = 1,
	minus = 2,
	mult = 3,
	division = 4,

	// condition tokens
	equals = 5,
	hashtag = 6,
	lessThan = 7,
	lessThanEqual = 8,
	greaterThan = 9,
	greaterThanEqual = 10,
	odd = 11,

	// other
	identifier = 12,
	procedure = 13,
	number = 14,
	variable = 15
};

class opTreeEntry {
public:
	int type;
	int value;
	opTreeEntry();
	opTreeEntry(int, int = 0);
	opTreeEntry(int, string);
	friend ostream & operator << (ostream &, const opTreeEntry &);
};

class opTree : public tree<opTreeEntry> {
public:
	opTree(opTreeEntry);
	opTree(opTreeEntry, opTree *);
	opTree(opTreeEntry, opTree *, opTree *);
	int eval();
	void aassemble(ostream & = cout, int level = 0);
};
