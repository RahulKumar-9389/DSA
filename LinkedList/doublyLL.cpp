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

    vector<int> arr = {2, 5, 19, 20, 11};
    Node *head = convertArrToDLL(arr);
    cout << "Doubly LinkedList is: ";
    printDoublyLL(head);
    return 0;
}