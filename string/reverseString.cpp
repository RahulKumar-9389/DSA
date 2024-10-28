#include <iostream>
using namespace std;

void reverseString(string str)
{
    int start = str[0];
    int end = str.length();

    while (start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

int main()
{

    string str;
    cout << "Enter the string: ";
    cin >> str;
    reverseString(str);
    cout << str;

    return 0;
}