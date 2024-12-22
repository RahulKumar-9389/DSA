#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

bool isBST(Node *root, int prev)
{
    if (!root)
    {
        return true;
    }

    if (!isBST(root->left, prev))
    {
        return false;
    }

    if (root->data <= prev)
    {
        return false;
    }

    prev = root->data;

    return isBST(root->right, prev);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(4);
    root->right = new Node(20);

    root->left->left = new Node(2);
    root->left->right = new Node(8);

    root->right->left = new Node(18);
    root->right->right = new Node(24);

    int prev = -1;
    if (isBST(root, prev))
    {
        cout << "BST" << endl;
    }
    else
    {
        cout << "Not BST" << endl;
    }
    return 0;
}