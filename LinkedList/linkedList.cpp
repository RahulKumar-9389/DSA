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

Node *convertArrToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Print Linked List
void printLL(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Length of LinkedList
int getLengthOfLL(Node *&head)
{

    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Search element
int isPresent(Node *&head, int data)
{

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data = data)
        {
            return 1;
        }
        temp = temp->next;
    }
    return -1;
}

int main()
{

    vector<int> arr = {2, 5, 10, 11, 15};
    Node *head = convertArrToLL(arr);
    printLL(head);
    cout << "Length of LinkedList is: " << getLengthOfLL(head) << endl;
    isPresent(head, 5);
    if (isPresent(head, 5))
    {
        cout << "Element is present in LinkedList:)" << endl;
        ;
    }
    else
    {
        cout << "No such element present in LinkedList:(";
    }
    return 0;
}