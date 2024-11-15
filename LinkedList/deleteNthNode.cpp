#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to print the linked list
void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to delete the Nth node
// from the end of the linked list
Node *deleteNthNodeFromEnd(Node *head, int N)
{
    if (head == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head;

    int i = 0;
    while (i < N)
    {
        fast = fast->next;
        i++;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *deletedNode = slow->next;
    slow->next = slow->next->next;
    delete (deletedNode);

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 5;
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    head = deleteNthNodeFromEnd(head, N);
    printLL(head);

    return 0;
}