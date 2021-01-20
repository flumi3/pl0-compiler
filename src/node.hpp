#include "optree.h"

class Node {
public:
    virtual void print();
};

class EndNode : public Node {
public:
    EndNode();
    void print() override;
};

class AssignNode : public Node {
public:
    // ziel der zuweisung????
    string name;
    int scope;
    int level;
    opTree* expr;
    AssignNode(string, int, int, opTree*);
    void print() override;
};

class CallNode : public Node {
public:
    string name;
    int procNr;
    CallNode(string, int);
    void print() override;
};

class InputNode : public Node {
public:
    // ziel der eingabe?
    string name;
    int scope;
    int level;
    InputNode(string, int, int);
    void print() override;
};

class WriteNode : public Node {
public:
    string name;
    // expression zeiger
    opTree* expr;
    WriteNode(string, opTree*);
    void print() override;
};

class JumpfNode : public Node {
public:
    int jmpIndex;
    opTree* expr;
    JumpfNode(int, opTree*);
    void print() override;
};

class JumpNode : public Node {
public:
    // sprungzeiger, aber da wir mit einer linked list arbeiten oder so, wohl eher ein index oder ähnliches
    int jmpIndex;
    JumpNode(int);
    void print() override;
};

class NopNode : public Node {
public:
    NopNode();
    void print() override;
};
