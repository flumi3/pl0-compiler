#include "ast.h"

Ast::Ast() {
    vector<Node> nodes;
}

// Adds element at the end of the nodes list
void Ast::append_node(Node node) {
    this->nodes.push_back(node);
}

int main() {
    // Beispiel aus der Vorlesung: Folie 340

    // ========================= 3 (f) -> write -> end ===============================
    // create call node 3
    CallNode callNode3 = CallNode(3);

    // add write node
    WriteNode writeNode3 = WriteNode(new opTree(opTreeEntry(treeEntryType::number, 2)));
    callNode3.append_node(writeNode3);

    // add end node
    EndNode endNode3 = EndNode();
    callNode3.append_node(endNode3);
    // ================================================================================



    // ================= 2 (g) -> call 3 (f) -> write -> nop -> end ===================
    // create call node 2
    CallNode callNode2 = CallNode(2);

    // add call node 3
    callNode2.append_node(callNode3);

    // add write node
    WriteNode writeNode2 = WriteNode(new opTree(opTreeEntry(treeEntryType::number, 3)));
    callNode2.append_node(writeNode2);

    // add nop node
    NopNode nopNode2 = NopNode();
    callNode2.append_node(nopNode2);
    
    // add end node
    EndNode endNode2 = EndNode();
    callNode2.append_node(endNode2);
    // =================================================================================


    
    // =========================== 1 (f) -> write -> end ===============================
    // create call node 1
    CallNode callNode1 = CallNode(1);

    // add write node
    WriteNode writeNode1 = WriteNode(new opTree(opTreeEntry(treeEntryType::number, 1)));
    callNode1.append_node(writeNode1);

    // add end node
    EndNode endNode1 = EndNode();
    callNode1.append_node(endNode1);
    // =================================================================================



    // =========== 0 (main) -> call 1 (f) -> call 2 (g) -> nop -> end ==================
    // create ast
    Ast ast = Ast();

    // add call 1 (f)
    ast.append_node(callNode1);

    // add call 2 (g)
    ast.append_node(callNode2);

    // add nop
    NopNode nopNode0 = NopNode();
    ast.append_node(nopNode0);

    // add end
    EndNode endNode0 = EndNode();
    ast.append_node(endNode0);
    // =================================================================================

    return 0;
}
