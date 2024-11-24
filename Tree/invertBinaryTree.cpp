#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to build binary tree
Node *buildTree()
{
    // Initialize an empty queue
    queue<Node *> q;

    int x;
    cout << "Enter the root node value: ";
    cin >> x;

    // Create root node
    Node *root = new Node(x);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter the value of " << temp->data << " left child: ";
        cin >> leftData;

        if (leftData != -1)
        {
            // Create a new node for the left child
            Node *leftNode = new Node(leftData);
            temp->left = leftNode; // Link the left child
            q.push(leftNode);      // Add it to the queue
        }

        int rightData;
        cout << "Enter the value of " << temp->data << " right child: ";
        cin >> rightData;

        if (rightData != -1)
        {
            // Create a new node for the right child
            Node *rightNode = new Node(rightData);
            temp->right = rightNode; // Link the right child
            q.push(rightNode);       // Add it to the queue
        }
    }

    return root; // Return the root of the tree
}

// Function to print binary tree level
void printTree(Node *root)
{
    if (!root)
    {
        return;
    }

    // Initialize a queue
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left != nullptr)
        {
            q.push(temp->left);
        }

        if (temp->right != nullptr)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = buildTree();
    printTree(root);

    return 0;
}