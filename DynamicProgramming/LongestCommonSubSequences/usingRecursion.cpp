#include <iostream>
using namespace std;

int LCS(int i, int j, string &str1, string &str2)
{

    if (i == str1.size() || j == str2.size())
    {
        return 0;
    }
    else if (str1[i] == str2[j])
    {
        return 1 + LCS(i + 1, j + 1, str1, str2);
    }
    else
    {
        return max(LCS(i + 1, j, str1, str2), LCS(i, j + 1, str1, str2));
    }
}

int main()
{

    string str1 = "abcde";
    string str2 = "ace";

    cout << LCS(0, 0, str1, str2);

    return 0;
}