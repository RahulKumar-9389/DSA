#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Construnctor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to convert array into doubly linked list
Node *convertArrayToDoublyLinkedList(vector<int> &arr)
{
    if (arr.empty())
    {
        return NULL;
    }

    // Create head
    Node *head = new Node(arr[0]);

    // Create a temp which initial points to the head
    // Used to traverse linked list
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

// Function to print doubly linked list
void printDoublyLinkedList(Node *head)
{
    if (head == NULL)
    {
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

// Function to remove all occurrences of key in dll
Node *removeOccurrences(Node *head, int key)
{
    if (head == NULL)
    {
        return head;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (temp == head)
            {
                head = temp->next;
            }

            Node *nextNode = temp->next;
            Node *prevNode = temp->prev;

            if (nextNode != NULL)
            {
                nextNode->prev = prevNode;
            }

            if (prevNode != NULL)
            {
                prevNode->next = nextNode;
            }

            delete (temp);
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{

    vector<int> arr = {4, 10, 10, 6, 10};
    Node *head = convertArrayToDoublyLinkedList(arr);

    head = removeOccurrences(head, 10);
    // Print the list
    printDoublyLinkedList(head);

    return 0;
}