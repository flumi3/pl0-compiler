#include "node.h"
#include <vector>

using namespace std;

class Ast {
public: 
    vector<Node> nodes;
    Ast();
    void append_node(Node);
};
