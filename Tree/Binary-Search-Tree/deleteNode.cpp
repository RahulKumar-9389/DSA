#include <iostream>
using namespace std;

// Define the structure for a node in the BST
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor to create a new node
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the minimum node in a given BST (used to find inorder successor)
Node *findMin(Node *root)
{
    while (root && root->left)
    {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node *deleteNode(Node *root, int key)
{
    // Base case: If the tree is empty
    if (root == nullptr)
    {
        return root;
    }

    // Recursively search for the node to delete
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Case 1: Node with only one child or no child
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        // Get the inorder successor (smallest in the right subtree)
        Node *temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform an inorder traversal (for testing purposes)
void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main function to demonstrate deletion in a BST
int main()
{
    // Create a sample BST
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    // Delete a node
    int key = 50; // Node to be deleted
    root = deleteNode(root, key);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
