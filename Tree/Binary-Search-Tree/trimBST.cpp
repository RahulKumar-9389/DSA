#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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

TreeNode *trimBST(TreeNode *root, int low, int high)
{
    if (!root)
        return nullptr;
    if (root->val < low)
        return trimBST(root->right, low, high);
    if (root->val > high)
        return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    TreeNode *root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);

    cout << "Original Tree (Inorder): ";
    inorder(root);
    cout << endl;

    int low = 4, high = 8;
    root = trimBST(root, low, high);

    cout << "Trimmed Tree (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
