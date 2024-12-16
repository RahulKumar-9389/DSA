#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

Node *solve(int arr[], int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = start + ((end - start) / 2);

    // Create a new node
    Node *root = new Node(arr[mid]);

    // create left
    root->left = solve(arr, start, mid - 1);

    // create right
    root->right = solve(arr, mid + 1, end);

    return root;
}

Node *arrayToTree(int arr[])
{
    return solve(arr, 0, 4);
}

void preOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << ",";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{

    int arr[5] = {-10, -3, 0, 5, 9};
    Node *root = arrayToTree(arr);
    preOrderTraversal(root);
    return 0;
}