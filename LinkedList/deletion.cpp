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

// ======================= Delete Head Node ==================
Node *deleteHead(Node *head)
{
    if (!head)
        return NULL;
    Node *temp = head;
    head = head->next;
    delete (temp);
    return head;
}

// ========================== Delete Tail Node ====================
Node *deleteTail(Node *head)
{

    if (!head)
        return NULL;

    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = NULL;
    return head;
}

// =============================== DELETE KTH  NODE ===========================
Node *deleteK(Node *head, int k)
{
    if (head == NULL)
        return head;

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
        return head;
    }

    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete (temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
}

// =============================== DELETE K  NODE ===========================
Node *deleteEl(Node *head, int el)
{
    if (head == NULL)
    {
        return head;
    }

    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next;
            delete (temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
}

int main()
{

    vector<int> arr = {5, 11, 4, 8, 10};
    Node *head = convertArrToLL(arr);

    cout << "LinkedList without any deletion: ";
    printList(head);

    // After deletion head is changed
    cout << "LinkedList after head deletion: ";
    head = deleteHead(head);
    printList(head);

    cout << "LinkedList after Tail deletion: ";
    head = deleteTail(head);
    printList(head);

    cout << "LinkedList after remove 2th element: ";
    head = deleteK(head, 2);
    printList(head);

    cout << "LinkedList after removing 8: ";
    head = deleteEl(head, 8);
    printList(head);
    return 0;
}