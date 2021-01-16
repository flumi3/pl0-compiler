#include "../operator_tree/optree.h"

class Node {
public:
    Node();
};

class EndNode : public Node {
public:
    EndNode();
};

class AssignNode : public Node {
public:
    // ziel der zuweisung????
    int scope;
    int level;
    opTree* expr;
    AssignNode(int, int, opTree*);
};

class CallNode : public Node {
public:
    int procNr;
    vector<Node> call_nodes; // Every call node can have a list of other nodes
    CallNode(int);
    void append_node(Node);
};

class InputNode : public Node {
public:
    // ziel der eingabe?
    int scope;
    int level;
    InputNode(int, int);
};

class WriteNode : public Node {
public:
    // expression zeiger
    opTree* expr;
    WriteNode(opTree*);
};

class JumpfNode : public Node {
public:
    int jmpIndex;
    opTree* expr;
    JumpfNode(int, opTree*);
};

class JumpNode : public Node {
public:
    // sprungzeiger, aber da wir mit einer linked list arbeiten oder so, wohl eher ein index oder ähnliches
    int jmpIndex;
    JumpNode(int);
};

class NopNode : public Node {
public:
    NopNode();
};
