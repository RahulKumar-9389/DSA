#include <iostream>
using namespace std;

bool isPalindrome(int x)
{

    // if number is less than 0 return false
    if (x < 0)
    {
        return false;
    }

    long long ans = 0;

    // store orignal number
    int orignalNum = x;

    while (x > 0)
    {

        // find the last digit
        int digit = x % 10;

        // add last digit to ans
        ans = (ans * 10) + digit;
        x = x / 10;
    }

    if (ans == orignalNum)
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

    int num;
    cout << "Enter the number: ";
    cin >> num;
    if (isPalindrome(num))
    {
        cout << num << " is a palindrome number!";
    }
    else
    {
        cout << num << " is not a palindrome number!";
    }

    return 0;
}