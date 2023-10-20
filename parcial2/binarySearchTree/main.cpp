#include "bst.hpp"

int main() {
    BinarySearchTree bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);

    bst.printInorder();
    bst.deleteNode(3);
    cout << endl;
    bst.printInorder();
    return 0;
}