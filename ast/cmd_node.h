#include "operator_tree/optree.h"

class AssignNode {
    public:
        // ziel der zuweisung????
        int scope;
        int level;
        AssignNode(int scope, int level);
};

class CallNode {
    public:
        int procNr;
        CallNode(int procNr);
};

class InputNode {
    public:
        // ziel der eingabe?
        int scope;
        int level;
        InputNode(int scope, int level);
};

class WriteNode {
    public:
        // expression zeiger
        opTree* expression;
        WriteNode(opTree* expr);
};

class JumpfNode {
    public:
        // expression zeiger
        opTree* expression;
        JumpfNode(opTree* expr);
};

class JumpNode {
    public:
        // sprungzeiger, aber da wir mit einer linked list arbeiten oder so, wohl eher ein index oder ähnliches
        JumpNode();
};
