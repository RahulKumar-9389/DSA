#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    // constructor
    Node(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

// Modified buildTree function
Node *buildTree(vector<int> &arr, int &index, int bound)
{
    // Base condition: if index is out of bounds or the current element is greater than the bound
    if (index == arr.size() || arr[index] > bound)
    {
        return nullptr;
    }

    // Create a new node with the current element
    Node *root = new Node(arr[index]);
    index++; // Increment the index after creating the node

    // Build the left subtree, where all nodes should be smaller than the current node's value
    root->left = buildTree(arr, index, root->val);

    // Build the right subtree, where all nodes should be greater than the current node's value
    root->right = buildTree(arr, index, bound);

    return root;
}

int main()
{
    vector<int> arr = {8, 5, 1, 7, 10, 12};
    int index = 0; // Initialize index as 0
    Node *root = buildTree(arr, index, INT_MAX);

    // Output the root, left child, and right child values
    cout << root->val << endl;        // Should print 8
    cout << root->left->val << endl;  // Should print 5
    cout << root->right->val << endl; // Should print 10

    return 0;
}
