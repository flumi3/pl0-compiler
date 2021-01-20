#include "ast.hpp"

Ast::Ast() {
    vector<vector<Node*>> procedures;
}

void Ast::print() {
    for (int i = 0; i < this->procedures.size(); i++) {
        cout << "procedure: " << i << endl;
        for (Node* node : procedures[i]) {
            node->print();
        }
        cout << "\n";
    }
}

/*
int main() {

    // holding all procedures
    vector<vector<Node*>> procedureList;
    
    // main procedure
    vector<Node*> proc_main;
    // create nodes of this procedure
    Node *call_f_1 = new CallNode("call f(1)", 1);
    Node *call_g_2 = new CallNode("call g(2)", 2);
    Node *nop_main = new NopNode();
    Node *end_main = new EndNode();
    // add those nodes to the main proc
    proc_main.push_back(call_f_1);
    proc_main.push_back(call_g_2);
    proc_main.push_back(end_main);
    // add the main proc to vector holding all procedures
    procedureList.push_back(proc_main);

    // f(1) procedure
    vector<Node*> proc_f_1;
    // create nodes of the proc
    Node *write_one = new WriteNode("write 1", new opTree(opTreeEntry(treeEntryType::number, 1)));
    Node *end_f = new EndNode();
    // add nodes to the proc
    proc_f_1.push_back(write_one);
    proc_f_1.push_back(end_f);
    // add procedure to vector of procedures
    procedureList.push_back(proc_f_1);

    // g(2) procedure
    vector<Node*> proc_g_2;
    // create nodes of this proc
    Node *call_f_3 = new CallNode("call f(3)", 3);
    Node *write_three = new WriteNode("write 3", new opTree(opTreeEntry(treeEntryType::number, 3)));
    Node *nop_g = new NopNode();
    Node *end_g = new EndNode();
    // add nodes to the proc
    proc_g_2.push_back(call_f_3);
    proc_g_2.push_back(write_three);
    proc_g_2.push_back(nop_g);
    proc_g_2.push_back(end_g);
    // add proc to vector of procs
    procedureList.push_back(proc_g_2);

    // f(3) procedure
    vector<Node*> proc_f_3;
    // create nodes of this proc
    Node *write_two = new WriteNode("write 2", new opTree(opTreeEntry(treeEntryType::number, 2)));
    Node *end_f_3 = new EndNode();
    // add nodes to the proc
    proc_f_3.push_back(write_two);
    proc_f_3.push_back(end_f_3);
    // add proc to vector of procs
    procedureList.push_back(proc_f_3);

    // Create AST
    Ast ast;
    ast.procedures = procedureList;
    ast.print();

    return 0;
}
*/
