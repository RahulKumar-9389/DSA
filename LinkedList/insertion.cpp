#include <iostream>
#include <vector>
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

// Convert array into LinkedList
Node *convertArrToLL(vector<int> &arr)
{
    if (arr.empty())
        return NULL;

    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *insertAtPosition(Node *head, int data, int pos)
{
    if (head == NULL)
    {
        if (pos == 1)
        {
            return new Node(data);
        }
        else
        {
            return head;
        }
    }

    if (pos == 1) // insert element at head
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        return head;
    }

    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        if (count == (pos - 1))
        {
            Node *newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
}

int main()
{

    vector<int> arr = {5, 11, 4, 8, 10};
    Node *head = convertArrToLL(arr);

    cout << "LinkedList is: ";
    printList(head);

    cout << "After inserting element, LinkedList is: ";
    head = insertAtPosition(head, 100, 5);
    printList(head);

    return 0;
}