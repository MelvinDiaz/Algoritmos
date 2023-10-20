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

    void swap(Node *&a, Node *&b)
    {
        Node *temp = a;
        a = b;
        b = temp;
    }

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
            node->right->parent = node;
        }
        else if (data < node->data)
        {
            // Will go left, then assign the parent as the current node.
            insert(data, node->left);
            node->left->parent = node;
        }
    }

    // Printing inorder.
    // Goes to left, prints, goes to right. Then, goes up and prints.
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

    // Delete
    void deleteNode(int data, Node *&node)
    {
        if (node == nullptr)
            return;
        else if (data > node->data)
        {
            deleteNode(data, node->right);
        }
        else if (data < node->data)
        {
            deleteNode(data, node->left);
        }
        else
        {
            // Check if the node has no children. Easy case
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                node = nullptr;
                
            }
            else if (node->left == nullptr)
            {
                // Pass the node to be deleted to the right with swap. Then delete it.
                node->right->parent = node->parent;
                Node *temp = node;
                node = node->right;
                delete temp;
                
            }
            else if (node->right == nullptr)
            {
                node->left->parent = node->parent;
                Node *temp = node;
                node = node->left;
                delete temp;
                
            }
            else
            {
                // Find the successor of the node to be deleted
                Node *successor = findSuccessor(node);
                // We assign the value of the successor to the node to be deleted.
                node->data = successor->data;
                // We send the successor.data to be deleted, as we changed the node.data to be the successor.data. 
                // We also send node.right as we know that the successor will be in the right subtree of node.
                deleteNode(successor->data, node->right);
            }
        }
    }

    Node *findSuccessor(Node *&node)
    {
        
        Node *successor = node->right;
        while (successor->left != nullptr)
        {
            successor = successor->left;
        }
        return successor;
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

    void deleteNode(int data)
    {
        deleteNode(data, root);
    }
};