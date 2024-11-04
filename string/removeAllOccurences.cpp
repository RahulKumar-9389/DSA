#include <iostream>
using namespace std;

void removeAllOccurences(string &str, string part)
{
    while (str.length() > 0 && str.find(part) < str.length())
    {
        str.erase(str.find(part), part.length());
    }
}

int main()
{

    string str = "daabcbaabcbc";
    removeAllOccurences(str, "abc");
    cout << str;

    return 0;
}