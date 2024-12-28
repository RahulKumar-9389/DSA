#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void applyModulus(Node *root, int mod, vector<int> &result)
{
    if (root == nullptr)
    {
        return;
    }
    applyModulus(root->left, mod, result);
    result.push_back(root->data % mod);
    applyModulus(root->right, mod, result);
}

Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return new Node(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        root->right = insert(root->right, key); // Duplicates go to the right subtree
    }
    return root;
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    insert(root, 30); // Duplicate element

    int mod = 7;
    vector<int> result;
    applyModulus(root, mod, result);

    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
