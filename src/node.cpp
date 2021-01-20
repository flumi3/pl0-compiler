#include "node.hpp"
#include <vector>
using namespace std; 

void Node::print() {
    cout << "this should not be printed" << endl;
}

EndNode::EndNode() {}
void EndNode::print() {
    cout << "EndNode()" << endl;
}

AssignNode::AssignNode(string name_, int scope_, int level_, opTree* tree) {
    name = name_;
    scope = scope_;
    level = level_;
    expr = tree;
}
void AssignNode::print() {
    cout << "AssignNode(name=" << this->name << ", scope=" << this->scope << ", level=" << this->level << ")" << endl; 
}

CallNode::CallNode(string name_, int proc_num) {
    name = name_;
    procNr = proc_num;
}
void CallNode::print() {
    cout << "CallNode(name=" << this->name << ", procNr=" << this->procNr << ")" << endl;
} 

InputNode::InputNode(string name_, int scope_, int level_) {
    name = name_;
    scope = scope_;
    level = level_;
}
void InputNode::print() {
    cout << "InputNode(name=" << this->name << ", scope=" << this->scope << ", level=" << this->level << ")" << endl;
}

WriteNode::WriteNode(string name_, opTree* tree) {
    name = name_;
    expr = tree;
}
void WriteNode::print() {
    cout << "WriteNode(name=" << this->name << ")" << endl;
}

JumpfNode::JumpfNode(int index, opTree* tree) {
    jmpIndex = index;
    expr = tree;
}
void JumpfNode::print() {
    cout << "JumpfNode(jmpIndex=" << this->jmpIndex << ")" << endl;
}

JumpNode::JumpNode(int index) {
    jmpIndex = index;
}
void JumpNode::print() {
    cout << "JumpNode(jmpIndex=" << this->jmpIndex << ")" << endl;
}

NopNode::NopNode() {}
void NopNode::print() {
    cout << "NopNode()" << endl; 
}
