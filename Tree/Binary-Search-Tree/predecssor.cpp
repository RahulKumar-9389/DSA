#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

int predecessor(Node *root, int key)
{
    int predecessor = -1;

    while (root)
    {
        if (key <= root->val)
        {
            // If key is smaller or equal, move to the left subtree.
            root = root->left;
        }
        else
        {
            // If key is greater, update the predecessor to current node's value.
            predecessor = root->val;
            root = root->right;
        }
    }
    return predecessor;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(9);

    cout << predecessor(root, 3); // It should return 2 as the predecessor of 3 in the tree.

    return 0;
}
