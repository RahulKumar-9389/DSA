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

class Stack
{
public:
    Node *top;
    int size;

    // Constructor
    Stack()
    {
        top = nullptr;
        size = 0;
    }

    void push(int data)
    {

        // Create a new node
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop()
    {
        if (top == nullptr)
        {
            return -1;
        }

        int topData = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
        return topData;
    }

    int Size()
    {
        return size;
    }

    int Top()
    {
        if (top == NULL)
            return -1;
        return top->data;
    }

    void printStack()
    {
        Node *current = top;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
    Stack s;
    s.push(10);
    cout << "Element popped: " << s.pop() << "\n";
    cout << "Stack size: " << s.Size() << "\n";
    cout << "stack's top element: " << s.Top() << "\n";

    return 0;
}