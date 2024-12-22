#include <iostream>
#include <climits>
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

void minimumDiffrence(Node *root, int &prev, int &ans)
{
    if (!root)
    {
        return;
    }

    minimumDiffrence(root->left, prev, ans);

    if (prev != INT_MIN)
    {
        ans = min(prev, abs(root->data - prev));
        prev = root->data;
    }

    minimumDiffrence(root->right, prev, ans);
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

    int prev = INT_MIN;
    int ans = INT_MAX;

    minimumDiffrence(root, prev, ans);
    cout << ans << prev;

    return 0;
}