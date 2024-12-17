#include <iostream>
#include <vector>
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

// helper function to print left view
void helper(Node *root, int level, vector<int> &ans)
{
    if (!root)
    {
        return;
    }

    if (level == ans.size())
    {
        ans.push_back(root->val);
    }

    helper(root->left, level + 1, ans);
    helper(root->right, level + 1, ans);
}

// Function to print the left view of binary tree
vector<int> leftView(Node *root)
{
    vector<int> ans;
    helper(root, 0, ans);
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(9);

    vector<int> result = leftView(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}