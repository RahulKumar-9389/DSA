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
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to build tree
Node *buildTree()
{
    int data;
    cout << "Enter the root node: ";
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }

    Node *temp = new Node(data);

    cout << "Enter left child of " << data << ": ";
    temp->left = buildTree();

    cout << "Enter right child of " << data << ": ";
    temp->right = buildTree();

    return temp;
}

// Function to print tree level order
void levelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    // Initialize a queue
    queue<Node *> q;
    q.push(root);

    cout << "Level Order Traversal: ";

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " ";

        // Enqueue left child
        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        // Enqueue right child
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
    cout << endl; // To make the output prettier
}

int main()
{
    Node *root = buildTree();  // Building the tree
    levelOrderTraversal(root); // Printing level order traversal

    return 0;
}
