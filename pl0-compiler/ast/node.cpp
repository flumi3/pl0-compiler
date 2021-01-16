#include "node.h"
#include <vector>
using namespace std; 

Node::Node() {}

EndNode::EndNode() {}

AssignNode::AssignNode(int scope_, int level_, opTree* tree) {
    scope = scope_;
    level = level_;
    expr = tree;
}

CallNode::CallNode(int proc_num) {
    procNr = proc_num;
    call_nodes = vector<Node>();
}

void CallNode::append_node(Node node) {
    call_nodes.push_back(node);
}

InputNode::InputNode(int scope_, int level_) {
    scope = scope_;
    level = level_;
}

WriteNode::WriteNode(opTree* tree) {
    expr = tree;
}

JumpfNode::JumpfNode(int index, opTree* tree) {
    jmpIndex = index;
    expr = tree;
}

JumpNode::JumpNode(int index) {
    jmpIndex = index;
}

NopNode::NopNode() {}
