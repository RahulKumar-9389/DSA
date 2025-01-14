#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n = 5;
    if (isPrime(n))
    {
        cout << "Given number is prime!";
    }
    else
    {
        cout << "Given number is not a prime number!";
    }
    return 0;
}