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
        this->next = nullptr;
    }
};

// Function to merge two sorted linked list
Node *mergeTwoLinkedList(Node *l1, Node *l2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->data <= l2->data)
        {
            temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
        }

        temp = temp->next;
    }

    if (l1 != nullptr)
    {
        temp->next = l1;
    }
    else
    {
        temp->next = l2;
    }

    Node *head = dummyNode->next;
    delete (dummyNode);
    return head;
}

// Function to find middle node
Node *findMiddle(Node *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Function to do merge sort
Node *mergeSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *middle = findMiddle(head);

    // Divide the list into two halves
    Node *left = head;
    Node *right = middle->next;
    middle->next = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);
    return mergeTwoLinkedList(left, right);
}

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        // Print the data of the current node
        cout << temp->data << " ";
        // Move to the next node
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    // Create a sample linkedlist 3->1->7->5->NULL
    Node *head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(7);
    head->next->next->next = new Node(5);
    printLinkedList(head);

    head = mergeSort(head);
    printLinkedList(head);

    return 0;
}