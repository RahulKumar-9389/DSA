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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node *temp1 = head1; // Points to the first LinkedList head
    Node *temp2 = head2; // Points to the second LinkedList head

    // Create a dummy node
    Node *dummyNode = new Node(-1);
    Node *current = dummyNode; // Points to the dummy node

    int carry = 0; // used to store carry

    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (temp1)
        {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2)
        {
            sum += temp2->data;
            temp2 = temp2->next;
        }

        Node *newNode = new Node(sum % 10);
        carry = sum / 10;
        current->next = newNode;
        current = newNode;
    }

    if (carry)
    {
        Node *newNode = new Node(carry);
        current->next = newNode;
    }
    return dummyNode->next;
}

// Print the LinkedList
Node *printLinkedList(Node *head)
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

    Node *head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(4); // Create first linked list 1->3->5->NULL
    printLinkedList(head1);

    Node *head2 = new Node(3);
    head2->next = new Node(7);
    head2->next->next = new Node(10);
    head2->next->next->next = new Node(8); // Create second LinkedList 3->7->10->20
    printLinkedList(head2);

    Node *head = addTwoNumbers(head1, head2);
    printLinkedList(head);

    return 0;
}