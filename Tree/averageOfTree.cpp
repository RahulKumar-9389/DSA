#include <iostream>
#include <vector>
#include <queue>
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

vector<double> averageOfLevels(Node *root)
{

    // Create a ans vector
    vector<double> ans;
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        int qlen = q.size();
        int sum = 0;
        for (int i = 0; i < qlen; i++)
        {
            Node *temp = q.front();
            q.pop();
            sum += temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        ans.push_back(sum / qlen);
    }
    return ans;
}

int main()
{

    Node *root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);

    root->right->left = new Node(15);
    root->right->right = new Node(7);

    vector<double> result = averageOfLevels(root);
    for (auto el : result)
    {
        cout << el << " ";
    }
    return 0;
}