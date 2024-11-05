#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string s)
{

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty())
            {
                if (s[i] == ')' && st.top() == '(' || s[i] == '}' && st.top() == '{' || s[i] == ']' && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    string str = "[{()}]";

    if (isValidParenthesis(str))
    {
        cout << "String having valid parenthesis!";
    }
    else
    {
        cout << "Invalid parenthesis!";
    }

    return 0;
}