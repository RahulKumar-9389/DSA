#include <iostream>
#include <algorithm>
using namespace std;

string reverseWord(string s)
{
    int n = s.size();
    reverse(s.begin(), s.end());

    string ans = "";
    bool firstWord = true; // Flag to check if it's the first word

    for (int i = 0; i < n; i++)
    {
        string word = "";
        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());
        if (word.length() > 0)
        {
            // Only add a space before the word if it's not the first word
            if (!firstWord)
            {
                ans += " ";
            }
            ans += word;
            firstWord = false; // Set flag to false after adding the first word
        }
    }

    return ans; // No need for substr(1) since we're handling spaces correctly
}

int main()
{
    string str = "My name is rahul kumar";
    cout << reverseWord(str);
    return 0;
}
