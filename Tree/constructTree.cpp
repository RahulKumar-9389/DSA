#include <iostream>
#include <vector>
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

int findPosition(vector<int> &in, int target, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == target)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTree(vector<int> &in, vector<int> &pre, int start, int end, int &index)
{
    if (start > end)
    {
        return nullptr;
    }

    // create the root node
    Node *root = new Node(pre[index]);
    index++; // Move to the next element in preorder

    // find the position of the root in inorder
    int pos = findPosition(in, root->data, start, end);

    // Recursively build the left and right subtrees
    root->left = buildTree(in, pre, start, pos - 1, index);
    root->right = buildTree(in, pre, pos + 1, end, index);

    return root;
}

void printInorder(Node *root)
{
    if (root == nullptr)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    vector<int> inorder = {4, 2, 8, 5, 9, 1, 6, 3, 7, 10};
    vector<int> preorder = {1, 2, 4, 5, 8, 9, 3, 6, 7, 10};

    int index = 0;
    Node *root = buildTree(inorder, preorder, 0, inorder.size() - 1, index);

    printInorder(root);
    return 0;
}
