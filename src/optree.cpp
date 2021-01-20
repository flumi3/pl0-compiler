#include <iostream>
#include "optree.h"

using namespace std;

// tree entry with type and int value
opTreeEntry::opTreeEntry(int _t, int _v): type(_t), value(_v) {}

// empty tree entry
opTreeEntry::opTreeEntry() {}

// tree with one entry
opTree::opTree(opTreeEntry e) {
	v = e;
}

// tree with entry and another tree as entry
opTree::opTree(opTreeEntry e, opTree * l) {
	v = e;
	append(l);
}

// tree with entry and 2 other trees as entries
opTree::opTree(opTreeEntry e, opTree * l, opTree * r) {
	v = e;
	append(l), append(r);
}

/*
int main() {
	opTree* t1 = new opTree(opTreeEntry(treeEntryType::number, 20));

	opTree* t3 = new opTree(opTreeEntry(treeEntryType::number, 100), t1);
	opTree* t2 = new opTree(opTreeEntry(treeEntryType::number, 5));

	opTree* t = new opTree(opTreeEntry(treeEntryType::minus), t3, t2);

	t->print(0);

	return 0;
}
*/


/* int opTree::eval() {
	int value = 0;
	switch(v.type) {
		case t_plus: value = ((opTree*)child[0])->eval() + ((opTree*)child[1])->eval(); break;
		case t_minus: value = (child.size() == 1) ? - ((opTree*)child[0])->eval() : ((opTree*)child[0])->eval() - ((opTree*)child[1])->eval(); break;
		case t_mal: value = ((opTree*)child[0])->eval() * ((opTree*)child[1])->eval(); break;
		case t_div: value = ((opTree*)child[0])->eval() / ((opTree*)child[1])->eval(); break;
 		case t_zahl: value = v.value; break;
	}
	return value;
} */

/* void opTree::aassemble(ostream & o, int level) {
	switch(v.type) {
		case t_plus:
			((opTree*)child[0])->aassemble(o, level + 1);
			((opTree*)child[1])->aassemble(o, level + 1);
			o << "\tadd\n";
			break;
		case t_minus:
			((opTree*)child[0])->aassemble(o, level + 1);
			if (child.size() == 1) {
				o << "\tchs\n";
			}
			else {
				((opTree*)child[1])->aassemble(o, level + 1);
				o << "\tsub\n";
			}
			break;
		case t_mal:
			((opTree*)child[0])->aassemble(o, level + 1);
			((opTree*)child[1])->aassemble(o, level + 1);
			o << "\tmult\n";
			break;
		case t_div:
			((opTree*)child[0])->aassemble(o, level + 1);
			((opTree*)child[1])->aassemble(o, level + 1);
			o << "\tdiv\n";
			break;

		case t_zahl:
			o << "\tloadc " << v.value << "\n";
			break;
	}
	if (!level)
		o << "\twrite" << endl;
} */

/* ostream & operator << (ostream &o , const opTreeEntry & e) {
	switch(e.type) {
		case t_plus: o << "+"; break;
		case t_minus: o << "-"; break;
		case t_mal: o << "*"; break;
		case t_div: o << "/"; break;
		case t_zahl: o << e.value; break;
		default: o << "error";
	}
	return o;
} */

/*
int main() {
	opTree * t = new opTree(opTreeEntry(t_minus));
//	t->append(new opTree(opTreeEntry(t_zahl,2)));
	t->append(new opTree(opTreeEntry(t_zahl,4)));
	t->postorder();
	cout << t->eval() << endl;
	t->aassemble();
}
*/
