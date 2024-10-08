#include <iostream>
using namespace std;

int getFactorial(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return num * getFactorial(num - 1);
}

int main()
{

    int n;
    cout << "Enter the number: ";
    cin >> n;

    int result = getFactorial(n);
    cout << "Factorial of " << n << " is " << result;

    return 0;
}