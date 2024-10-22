#include <iostream>
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

// Print the linkedlist
void printLinkedList(Node *head)
{
    if (head == NULL)
    {
        cout << "LinkedList is empty!";
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Reverse the linked list
Node *reverseLinkedList(Node *head)
{
    if (head == NULL)
    {
        cout << "LinkedList is empty!";
        return NULL;
    }

    if (head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *temp = head;

    while (temp != NULL)
    {
        Node *front = temp->next;

        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Orignal LinkedList is: ";
    printLinkedList(head);

    head = reverseLinkedList(head);
    cout << "Reversed LinkedList is: ";
    printLinkedList(head);

    return 0;
}