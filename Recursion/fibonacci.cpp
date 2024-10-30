#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n = 5;
    cout << fibonacci(n);

    int fib = 1;

    for (int i = n; i > 0; i--)
    {
        fib = fib * i;
    }

    cout << fib;
    return 0;
}