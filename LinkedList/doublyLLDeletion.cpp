#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// ================================ CONVERT ARR TO DLL ==========================

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
        temp = newNode;
    }
    return head;
}

// ================================== PRINT THE LIST =========================
void printDLL(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty!";
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

// ============================== DELETE THE HEAD NODE OF THE LIST ===================
Node *deleteHead(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        delete (head);
        return NULL;
    }

    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete (temp);
    return head;
}

// ============================== DELETE THE TAIL NODE OF THE LIST ===================

Node *deleteTail(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        delete (head);
        return NULL;
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->prev;
    tail->prev = NULL;
    newTail->next = NULL;
    delete (tail);
    return head;
}

// ================================ DELETE THE KTH ELEMENT FROM THE LIST ====================
Node *deleteKthElem(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    int count = 0;
    Node *temp = head;

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
    Node *front = temp->next;

    if (back == NULL && front == NULL)
    {
        return NULL;
    }
    else if (back == NULL)
    {
        return deleteHead(head);
    }
    else if (front == NULL)
    {
        return deleteTail(head);
    }
    else
    {
        back->next = front;
        front->prev = back;
        temp->next = NULL;
        temp->prev = NULL;
        delete (temp);
    }

    return head;
}

int main()
{

    vector<int> arr = {10, 20, 30, 40};
    Node *head = convertArrToDLL(arr);
    cout << "Doubly Linked List is: ";
    printDLL(head);

    head = deleteKthElem(head, 3);
    cout << "After removing list is: ";
    printDLL(head);

    return 0;
}