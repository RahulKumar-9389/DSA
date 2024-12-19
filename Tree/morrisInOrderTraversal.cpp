#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

vector<int> morrisInOrderTraversal(Node *root)
{
    vector<int> ans;

    while (root)
    {
        if (root->left == NULL)
        {
            ans.push_back(root->data);
            root = root->right;
        }
        else
        {
            Node *pre = root->left;
            while (pre->right != NULL && pre->right != root)
            {
                pre = pre->right;
            }

            if (pre->right == NULL)
            {
                pre->right = root;
                root = root->left;
            }
            else
            {
                pre->right = NULL;
                ans.push_back(root->data);
                root = root->right;
            }
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    vector<int> ans = morrisInOrderTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}