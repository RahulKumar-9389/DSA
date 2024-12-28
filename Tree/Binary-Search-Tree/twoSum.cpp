#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> seen;
        return dfs(root, k, seen);
    }

    bool dfs(TreeNode *node, int k, unordered_set<int> &seen)
    {
        if (!node)
            return false;

        // Check if the complement (k - node->val) is already in the seen set
        if (seen.count(k - node->val))
        {
            return true;
        }

        // Add current node's value to the seen set
        seen.insert(node->val);

        // Recur for left and right subtree
        return dfs(node->left, k, seen) || dfs(node->right, k, seen);
    }
};

// Helper function to create a binary tree node
TreeNode *createNode(int val)
{
    return new TreeNode(val);
}

// Test the solution
int main()
{
    // Create a sample binary search tree
    TreeNode *root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->right = createNode(7);

    Solution solution;
    int k = 9;

    if (solution.findTarget(root, k))
    {
        cout << "There exist two elements in the BST whose sum is " << k << endl;
    }
    else
    {
        cout << "No two elements in the BST sum to " << k << endl;
    }

    return 0;
}
