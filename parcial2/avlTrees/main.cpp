#include "avl.hpp"

int main()
{

    AVL avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(4);
    avl.insert(5);
    avl.insert(6);

    cout << "Inorder traversal: ";
    avl.printInorder();
    cout << "\n";

    return 0;
}