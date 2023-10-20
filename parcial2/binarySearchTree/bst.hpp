#include <iostream>
using namespace std;

class BinarySearchTree
{

private:
    // Basic structure
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        Node *parent;
    };
    Node *root;

    // Insert, recieves at first the node, then will go down the tree
    void insert(int data, Node *&node)
    {
        if (node == nullptr)
        {
            node = new Node;
            node->data = data;
            node->left = nullptr;
            node->right = nullptr;
        }
        else if (data > node->data)
        {
            // Will go right, then assign the parent as the current node.
            insert(data, node->right);
            node->parent = node;
        }
        else if (data < node->data)
        {
            // Will go left, then assign the parent as the current node.
            insert(data, node->left);
            node->parent = node;
        }
    }

    //Printing inorder.
    //Goes to left, prints, goes to right. Then, goes up and prints.
    void printInorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        else
        {
            printInorder(node->left);
            cout << node->data << " ";
            printInorder(node->right);
        }
    }

public:
    // Constructor
    BinarySearchTree()
    {
        root = nullptr;
    }

    void insert(int data)
    {
        insert(data, root);
    }

    void printInorder()
    {
        cout << "Printing inorder: ";
        printInorder(root);
    }
};