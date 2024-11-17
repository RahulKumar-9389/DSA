#include <iostream>
using namespace std;

int firstOccurrence(string &str1, string &str2)
{

    // Find the size of both string
    int m = str1.length();
    int n = str2.length();

    for (int i = 0; i <= m - n; i++)
    {
        if (str1.substr(i, n) == str2)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    string str1 = "sadbutsad";
    string str2 = "sad";

    cout << firstOccurrence(str1, str2);

    return 0;
}