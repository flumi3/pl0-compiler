#pragma once

#include <iostream>
#include <vector>

using namespace std;

template <class T> class tree {
public:
	tree();
	tree(T);
	tree(T, tree<T> *);
	tree(T, tree<T> *, tree<T> *);
	tree(T, tree<T> *, tree<T> *, tree<T> *);
	void set(T p);
	T get();
	void ascii(ostream & o = cout, int level = 0);
	void tikz(ostream & o = cout, int level = 0, int path = 0);
	void tikz_path(ostream & o = cout, int level = 0);
	void postorder(ostream & o = cout, int level = 0);
	void append(tree *);
	void child_copy(tree *); // Evtl zukuenftig
	int size();
	tree<T> * operator [] (int);
protected:
	vector<tree *> child;
	T v;
};

template <class T> tree<T> * tree<T>::operator [] (int index) {
	return (index < 0 || index >= child.size()) ? nullptr : child[index];
}

template <class T> int tree<T>::size() {
	return child.size();
}

template <class T> tree<T>::tree(T _v) :v(_v) {}

template <class T> tree<T>::tree(T _v ,tree<T> * p) : v(_v) {
	append(p);
}

template <class T> tree<T>::tree(T _v ,tree<T> * p1, tree<T> * p2) : v(_v) {
	append(p1), append(p2);
}

template <class T> tree<T>::tree(T _v ,tree<T> * p1, tree<T> * p2, tree<T> * p3) : v(_v) {
	append(p1), append(p2), append(p3);
}

template <class T>  tree<T>::tree() {
}

template <class T> void tree<T>::set(T _v) {
	v = _v;
}

template <class T> T tree<T>::get() {
	return v;
}

template <class T> void tree<T>::append(tree * t) {
	child.push_back(t);
}

template <class T> void tree<T>::child_copy(tree * t) {
	child = t->child;
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
	if (!level)
		printf("\\draw [red, >->] plot [smooth, tension=.75] coordinates {\n");
	if (child.size() == 0) {
		o << "([xshift=-4mm]" << this << ")\n";
		o << "([yshift=-4mm]" << this << ")\n";
		o << "([xshift=+4mm]" << this << ")\n";
	}
/*	else if (child.size() == 1) {
		o << "([xshift=-4mm]" << this << ")\n";
		child[0]->tikz_path(o, level + 1);
		o << "([xshift=+4mm]" << this << ")\n";
	}*/
	else if (child.size() == 2) {
		o << "([xshift=-4mm]" << this << ")\n";
		child[0]->tikz_path(o, level + 1);
		o << "([yshift=-4mm]" << this << ")\n";
		child[1]->tikz_path(o, level + 1);
		o << "([xshift=+4mm]" << this << ")\n";
	}
	else  {
		o << "([xshift=-4mm]" << this << ")\n";
		for (int i = 0; i < child.size(); i++)
			child[i]->tikz_path(o, level + 1);
		o << "([xshift=+4mm]" << this << ")\n";
	}
	if (!level)
		printf("};\n");
}


/*int main() {
	tree<int> *t = new tree<int> (4711);

	t->append(new tree<int> (123));
	t->append(new tree<int> (321));
	//t->child[0]->append(new tree<int> (-1));
	t->ascii();
	t->postorder();
	return 0;
}*/
