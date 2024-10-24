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

// Function to delete the middle node of the linkedlist
Node *deleteMiddleNode(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *fast = head;
    Node *slow = head;
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;
    delete slow;
    return head;
}

// Function to print LinkedList
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    // Create a sample LinkedList 1->2->3->4->5->NULL
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Orignal LinkedList is: ";
    printLinkedList(head);

    head = deleteMiddleNode(head);
    cout << "After deleting the middle LinkedList is: ";
    printLinkedList(head);
    return 0;
}