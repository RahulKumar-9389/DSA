#include <iostream>
using namespace std;

// Define a structure for the binary tree node
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor to create a new node
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Function to calculate the size of the binary tree
int calculateSize(Node *root)
{
    // Base case: If the tree is empty, size is 0
    if (root == nullptr)
    {
        return 0;
    }

    // Recursive case: Size is 1 + size of left subtree + size of right subtree
    return 1 + calculateSize(root->left) + calculateSize(root->right);
}

int main()
{
    // Create a simple binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Calculate the size of the binary tree
    cout << "Size of the binary tree: " << calculateSize(root) << endl;

    return 0;
}
