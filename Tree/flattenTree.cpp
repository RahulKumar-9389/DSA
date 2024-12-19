#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void flatten(Node *root)
{

    while (root)
    {
        if (!root->left)
        {
            root = root->right;
        }
        else
        {
            Node *pre = root->left;
            while (pre->right)
            {
                pre = pre->right;
            }
            pre->right = root->right;
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    return 0;
}