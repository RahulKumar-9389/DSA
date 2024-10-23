#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to detect a loop in linkedlist
bool isLoopPresent(Node *head)
{
    if (!head || !head->next)
    {
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false; // If no loop detected
}

int main()
{

    // Create a sample LinkedList with loop
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    // Create a loop
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;

    if (isLoopPresent(head))
    {
        cout << "Loop detected in the LinkedList!" << endl;
    }
    else
    {
        cout << "No loop detected in the given LinkedList!" << endl;
    }

    return 0;
}