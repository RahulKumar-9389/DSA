#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    stack<int> st;
    int min = -1;

    // push
    void push(int val)
    {
        if (st.empty())
        {
            min = val;
            st.push(val);
        }
        else
        {
            if (val > min)
            {
                st.push(val);
            }
            else
            {
                st.push(((2 * val) - min));
                min = val;
            }
        }
    }

    // pop
    void pop()
    {
        if (st.empty())
        {
            cout << "Stack is already empty!";
            return;
        }

        int x = st.top();
        st.pop();

        if (x < min)
        {
            min = ((2 * min) - x);
        }
    }

    // top element
    int Top()
    {
        if (st.empty())
        {
            cout << "Stack is empty!";
            return -1;
        }

        int x = st.top();

        if (x < min)
        {
            return min;
        }
        else
        {
            return x;
        }
    }

    // min element
    int getMin()
    {
        return min;
    }
};

int main()
{
    Stack s;
    s.push(12);
    s.push(15);
    s.push(10);
    s.push(8);
    s.push(9);

    return 0;
}