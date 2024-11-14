#include <iostream>
using namespace std;

bool isSubsequence(string s, string t)
{

    // intialize two pointers
    int i = 0;
    int j = 0;

    while (i < s.length() && j < t.length())
    {

        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    if (i == s.length())
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

    string s = "abc";
    string t = "ahbgdc";

    if (isSubsequence(s, t))
    {
        cout << "This is a subsequences!";
    }
    else
    {
        cout << "This is not a subsequences!";
    }

    return 0;
}