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

// Print the LinkedList
void printLinkedList(Node *head)
{
    if (head == NULL)
    {
        cout << "LinkedList is empty!" << endl;
        return;
    }

    Node *temp = head; // Create a temporary node which point to the head of the linkedlist

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *oddEvenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *odd = head;        // Points to the firts node of the list
    Node *even = head->next; // Points to the second node of the list
    Node *evenHead = head->next;

    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5); // Create a LinkedList with elements 1->2->3->4->5

    cout << "Orignal LinkedList is: ";
    printLinkedList(head);

    oddEvenLinkedList(head);
    cout << "OddEven LinkedList is: ";
    printLinkedList(head);

    return 0;
}