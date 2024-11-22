using namespace std;
#include <iostream>
#include <vector>
#include <stack>

int evalRPN(vector<string> &tokens)
{

    // Intialize a stack data structure
    stack<int> st;

    for (int i = 0; i < tokens.size(); i++)
    {

        // chek if the token is an operand
        if (tokens[i] != "+" || tokens[i] != "-" || tokens[i] != "*" || tokens[i] != "/")
        {
            // push into stack
            st.push(stoi(tokens[i]));
        }
        else
        {
            int y = st.top();
            st.pop();
            int x = st.top();
            st.pop();

            if (tokens[i] == "+")
            {
                st.push(x + y);
            }
            else if (tokens[i] == "-")
            {
                st.push(x - y);
            }
            else if (tokens[i] == "*")
            {
                st.push(x * y);
            }
            else
            {
                st.push(x / y);
            }
        }
    }

    return st.top();
}

int main()
{

    vector<string> arr = {"2", "1", "+", "3", "*"};
    cout << evalRPN(arr);
    return 0;
}