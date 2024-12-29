#include <iostream>
#include <climits>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int minDiffInBST(TreeNode *root)
    {
        int minDiff = INT_MAX;
        int prev = -1;
        inorderTraversal(root, prev, minDiff);
        return minDiff;
    }

private:
    void inorderTraversal(TreeNode *root, int &prev, int &minDiff)
    {
        if (!root)
            return;

        inorderTraversal(root->left, prev, minDiff);

        if (prev != -1)
        {
            minDiff = min(minDiff, root->val - prev);
        }
        prev = root->val;

        inorderTraversal(root->right, prev, minDiff);
    }
};

TreeNode *insert(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);
    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

int main()
{
    TreeNode *root = nullptr;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);

    Solution solution;
    int result = solution.minDiffInBST(root);
    cout << "Minimum difference: " << result << endl;

    return 0;
}
