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

void printLinkedList(Node *head)
{

    if (head == NULL)
    {
        cout << "LinkedList is empty!" << endl;
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

Node *sort012(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Crete three dummy node
    Node *zeroDummy = new Node(-1);
    Node *oneDummy = new Node(-1);
    Node *twoDummy = new Node(-1);

    // Create three pointer
    Node *zero = zeroDummy; // Used to traverse zero list
    Node *one = oneDummy;   // Used to traverse one list
    Node *two = twoDummy;   // Used to traverse two list

    Node *temp = head; // Traverse the orignal list

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }

    zero->next = (oneDummy->next) ? (oneDummy->next) : (twoDummy->next);
    one->next = twoDummy->next;
    two->next = NULL;

    Node *newHead = zeroDummy->next;

    // Delete all dummies nodes
    delete (zeroDummy);
    delete (oneDummy);
    delete (twoDummy);

    // Return new head
    return newHead;
}

int main()
{

    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(2);

    cout << "Orignal Linked List is: ";
    printLinkedList(head);

    head = sort012(head);
    cout << "After sorting LinkedList is: ";
    printLinkedList(head);
    return 0;
}