#include <iostream>
using namespace std;

int uniquePath(int m, int n)
{
    if (m == 0 && n == 0)
    {
        return 1;
    }

    if (m < 0 || n < 0)
    {
        return 0;
    }

    int up = uniquePath(m - 1, n);
    int left = uniquePath(m, n - 1);

    return up + left;
}

int main()
{

    int m = 3;
    int n = 3;

    cout << uniquePath(m - 1, n - 1);
    return 0;
}