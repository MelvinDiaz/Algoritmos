#include "bst.hpp"

int main() {
    BinarySearchTree bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(6);
    bst.insert(8);
    bst.insert(4);
    bst.insert(2);
    bst.insert(1);
    bst.insert(9);
    bst.insert(10);
    bst.insert(11);

    bst.printInorder();
    bst.deleteNode(3);
    cout << endl;
    bst.printInorder();
    cout << "\nNumber of nodes in the tree: " << bst.countNodes() << "\n";
    return 0;
}