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

int sucessor(Node *root, int key)
{

    int sucessor = -1;

    while (root)
    {
        if (key >= root->val)
        {
            root = root->right;
        }
        else
        {
            sucessor = root->val;
            root = root->left;
        }
    }
    return sucessor;
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

    cout << sucessor(root, 3);

    return 0;
}