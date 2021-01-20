#include <iostream>
#include <vector>
#include "tree.hpp"

using namespace std;


template <class T>  tree<T>::tree(T p) {
	v = p;
}

template <class T>  tree<T>::tree() {
}

template <class T> void tree<T>::set(T p) {
	v = p;
}

template <class T> void tree<T>::append(tree * t) {
	child.push_back(t);
}

template <class T> void tree<T>::ascii(ostream & o, int level) {
	for (unsigned i=0; i < level; i++)
		o << "\t";
	o << v << " " << child.size() << endl;
	for (unsigned i=0; i < child.size(); i++) {
		child[i]->ascii(o, level + 1);
	}
}

template <class T> void tree<T>::postorder(ostream & o, int level) {
	for (unsigned i=0; i < child.size(); i++) {
		child[i]->postorder(o, level + 1);
	}
	o << v << " ";
	if (!level)
		o << endl;
}

template <class T> void tree<T>::tikz(ostream & o, int n, int path) {
	// Baum-Traversierung First-Order
	int i;
	
	if (!n) {
		o << "\\documentclass{svmono}\n";
		o << "\\input{/Users/wbantel/skripte/erweiterungen/erweiterungen}\n";
		o << "\\begin{document}\n";
		o << "\\begin{syntaxtree}\n";
		o << "\\Tree";
	}
	for (i = 0; i < n; i++)
		o << "\t";
	if (child.size()) {
//		o << "[." << v << endl;
		o << "[." << "\\node(" << this << "){" << v << "};" << endl;
		for (unsigned i=0; i < child.size(); i++)
			child[i]->tikz(o, n + 1);
		for (i = 0; i < n; i++)
			o << "\t";
		o << "]\n";
	}
	else
		o << "" << "\\node(" << this << "){" << v << "};" << endl;
	if (!n) {
		if (path)
			tikz_path(o, 0);
		o << "\\end{syntaxtree}\n";
		o << "\\end{document}\n";
	}
		
}

template <class T> void tree<T>::tikz_path(ostream & o, int level) {
	// Aktuell nur mit Binärbaum
	if (!level)
		printf("\\draw [red, >->] plot [smooth, tension=.75] coordinates {\n");
	if (child.size() == 0) {
		o << "([xshift=-4mm]" << this << ")\n";
		o << "([yshift=-4mm]" << this << ")\n";
		o << "([xshift=+4mm]" << this << ")\n";
	}
	else if (child.size() == 1) {
		o << "([xshift=-4mm]" << this << ")\n";
		child[0]->tikz_path(o, level + 1);
		o << "([xshift=+4mm]" << this << ")\n";
	}
	else  {
		o << "([xshift=-4mm]" << this << ")\n";
		child[0]->tikz_path(o, level + 1);
		o << "([yshift=-4mm]" << this << ")\n";
		child[1]->tikz_path(o, level + 1);
		o << "([xshift=+4mm]" << this << ")\n";
	}
	if (!level)
		printf("};\n");
}
