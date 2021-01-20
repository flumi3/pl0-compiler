#include "node.hpp"
#include <vector>

using namespace std;

class Ast {
public: 
    vector<vector<Node*>> procedures;
    Ast();
    void print();
};
