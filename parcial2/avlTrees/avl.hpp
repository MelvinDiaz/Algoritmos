#include <iostream>
using namespace std;

class AVL
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        Node *parent;
        int height;
    };

    Node *root;

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return node->height;
        }
    }

    Node *leftRotation(Node *&node)
    {
        // Set B to be the right child of A (node in this case)
        Node *B = node->right;
        // Set Y to be the left subtree of B (right child of A)
        Node *Y = B->left;

        // Set A as left child of B
        B->left = node;

        // Set Y as right child of A
        node->right = Y;

        // Update heights
        node->height = max(height(node->left), height(node->right)) + 1;
        B->height = max(height(B->left), height(B->right)) + 1;

        return B;
    }

    Node *rightRotation(Node *&node)
    {
        Node *B = node->left;
        // Set Y to be the left subtree of B (right child of A)
        Node *Y = B->right;

        B->right = node;
        node->left = Y;

        // Update heights
        node->height = max(height(node->left), height(node->right)) + 1;
        B->height = max(height(B->left), height(B->right)) + 1;

        return B;
    }

    void insert(Node *&node, int data)
    {
        if (node == nullptr)
        {
            node = new Node;
            node->data = data;
            node->left = nullptr;
            node->right = nullptr;
            node->height = 1;
        }
        else if (data > node->data)
        {
            insert(node->right, data);
        }
        else
        {
            insert(node->left, data);
        }

        // Update height of this ancestor node
        node->height = 1 + max(height(node->left), height(node->right));

        // Getting the balance of the node
        int balance = height(node->left) - height(node->right);

        // Left Left Case
        if (balance > 1 && data < node->left->data)
        {
            node = rightRotation(node);
        }

        // Right Right Case
        if (balance < -1 && data > node->right->data)
        {
            node = leftRotation(node);
        }

        // Left Right Case
        if (balance > 1 && data > node->left->data)
        {
            node->left = leftRotation(node->left);
            node = rightRotation(node);
        }

        // Right Left Case
        if (balance < -1 && data < node->right->data)
        {
            node->right = rightRotation(node->right);
            node = leftRotation(node);
        }
    }

    // This section is the same as bst
    void search(int data, Node *&node)
    {
        if (node == nullptr)
        {
            return;
        }
        else if (data > node->data)
        {
            // Will go right, then assign the parent as the current node.
            search(data, node->right);
            node->right->parent = node;
        }
        else if (data < node->data)
        {
            // Will go left, then assign the parent as the current node.
            search(data, node->left);
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

public:
    AVL()
    {
        root = nullptr;
    }

    void search(int data)
    {
        search(data, root);
    }

    void printInorder()
    {
        printInorder(root);
    }

    void insert(int data)
    {
        insert(root, data);
    }
};