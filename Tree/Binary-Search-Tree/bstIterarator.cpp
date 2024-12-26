#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

// Initialize bst iterator

class BTSItrator
{

private:
    stack<Node *> st;
    void pushToStack(Node *root)
    {
        while (root->left)
        {
            st.push(root);
            root = root->left;
        }
    }

public:
    // constructor
    BTSItrator(Node *root)
    {
        pushToStack(root);
    }

    // hasnext
    bool hasNext()
    {
        return !st.empty();
    }

    // next
    int next()
    {
        Node *temp = st.top();
        st.pop();
        pushToStack(temp->right);
        return temp->val;
    }
};

int main()
{
    Node *root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);

    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BTSItrator s(root);
    cout << s.next();
    cout << s.next();
    cout << s.hasNext();

    return 0;
}
