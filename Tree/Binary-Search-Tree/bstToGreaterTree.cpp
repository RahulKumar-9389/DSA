#include <iostream>
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

void convertBST(Node *root)
{
    if (!root)
    {
        return;
    }

    int sum = 0;

    convertBST(root->right);

    root->val = root->val + sum;
    sum = sum + root->val;

    convertBST(root->left);
}

int main()
{

    Node *root = new Node(4);
    root->left = new Node(1);
    root->right = new Node(6);

    root->left->left = new Node(0);
    root->left->right = new Node(2);

    root->right->right = new Node(7);
    root->right->left = new Node(5);
    return 0;
}