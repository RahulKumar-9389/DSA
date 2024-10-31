#include <iostream>
#include <vector>
using namespace std;

class Stack
{
public:
    int size;
    int *arr;
    int top;

    // Constructor
    Stack()
    {
        size = 100;
        arr = new int[size];
        top = -1;
    }

    // Function to push an element
    void push(int val)
    {
        top++;
        arr[top] = val;
    }

    // Function to pop an element
    int pop()
    {
        int val = arr[top];
        top--;
        return val;
    }

    // Function which return top element
    int Top()
    {
        return arr[top];
    }

    // Function to get size of the stack
    int Size()
    {
        return top + 1;
    }
};

int main()
{
    Stack s;
    vector<int> arr = {1, 3, 5, 9};

    for (int i = 0; i < arr.size(); i++)
    {
        s.push(arr[i]);
    }

    cout << "Size of the stack is: " << s.Size() << endl;
    cout << "Elements in stack: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << s.Top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}