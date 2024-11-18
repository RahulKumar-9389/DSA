#include <iostream>
using namespace std;

double myPow(int x, int n)
{

    n = abs(n);

    if (n == 0)
    {
        return 1;
    }

    if (n == 1)
    {
        return x;
    }

    if (n < 0)
    {
        double ans = myPow(x, n / 2);
        if (n % 2 == 0)
        {
            cout << 1 / ans * ans;
            return 1 / (ans * ans);
        }
        else
        {
            return 1 / (ans * ans * x);
        }
    }

    double ans = myPow(x, n / 2);
    if (n % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return ans * ans * x;
    }
}

int main()
{

    int x;
    cout << "Enter the base: ";
    cin >> x;

    int n;
    cout << "Enter the power: ";
    cin >> n;

    cout << myPow(x, n);

    return 0;
}