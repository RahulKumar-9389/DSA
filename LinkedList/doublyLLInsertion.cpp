#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *convertArrToDLL(vector<int> &arr)
{
    if (arr.empty())
    {
        return NULL;
    }

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
    }
    return head;
}

// ====================== Insert Node At the head of the linked list =====================
Node *insertAtHead(Node *head, int data)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}

// ====================== Insert Node At the tail of the linked list =====================
Node *insertAtTail(Node *head, int data)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    // Create a new node
    Node *newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    return head;
}

// ================ Insert the node before the kth position ===================
Node *insertBeforeKthPos(Node *head, int data, int k)
{
    if (k == 1)
    {
        return insertAtHead(head, data);
    }

    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }

    Node *back = temp->prev;
    Node *newNode = new Node(data);
    newNode->next = temp;
    newNode->prev = back;

    back->next = newNode;
    temp->prev = newNode;

    return head;
}

void printDoublyLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    vector<int> arr = {10, 15, 20, 25};
    Node *head = convertArrToDLL(arr);
    printDoublyLL(head);

    head = insertBeforeKthPos(head, 5, 1);
    printDoublyLL(head);

    head = insertBeforeKthPos(head, 30, 3);
    printDoublyLL(head);

    return 0;
}