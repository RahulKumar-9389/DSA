#include <iostream>
using namespace std;

class Node
{

public:
    int val;
    Node *left, *right;

    // constructor
    Node(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

// Function for inorder traversal
void InOrder(Node *root)
{
    if (!root)
    {
        return;
    }

    InOrder(root->left);

    cout << root->val << " ";

    InOrder(root->right);
}

// Function to fix the nodes of tree
void correctBST(Node *root)
{

    Node *current = nullptr;
    Node *prev = nullptr;
    Node *present = nullptr;

    Node *first = nullptr;
    Node *second = nullptr;

    while (root)
    {

        // left does not exist
        if (!root->left)
        {
            prev = present;
            present = root;

            if (prev && present->val < prev->val)
            {
                if (!first)
                {
                    first = prev;
                }
                second = present;
            }
        }
        else
        {
            current = root->left;

            while (current->right && current->right != root)
            {
                current = current->right;
            }

            if (!current->right)
            {
                current->right = root;
                root = root->left;
            }
            else
            {
                current->right = nullptr;
                root = root->right;
                prev = present;
                present = root;

                if (prev && present->val < prev->val)
                {
                    if (!first)
                    {
                        first = prev;
                    }
                    second = present;
                }
            }
        }
    }

    int num = first->val;
    first->val = second->val;
    second->val = num;
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(8);

    root->left->left = new Node(2);
    root->left->right = new Node(20);

    // Print tree without fixing nodes
    cout << endl;
    cout << "InOrder traversal of tree without fixing nodes: ";
    InOrder(root);

    // fix the tree
    correctBST(root);

    // Print tree after fixing nodes
    cout << "InOrder traversal after fixing nodes: ";
    InOrder(root);
    return 0;
}