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

// Function to find the length of the loop
int findLength(Node *slow, Node *fast)
{

    int count = 1;

    fast = fast->next;

    while (fast != slow)
    {
        count++;
        fast = fast->next;
    }
    return count;
};

// Function to detect a loop in linkedlist
int lengthOfLoop(Node *head)
{
    if (!head || !head->next)
    {
        return -1;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return findLength(slow, fast);
        }
    }
    return -1; // If no loop detected
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
    fifth->next = second;

    cout << "Length of the loop is: " << lengthOfLoop(head);

    return 0;
}