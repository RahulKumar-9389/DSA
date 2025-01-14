#include <iostream>
using namespace std;

int climbingStairs(int n)
{
    int prev1 = 1;
    int prev2 = 2;
    int current = 3;

    for (int i = 2; i < n; i++)
    {
        current = prev1 + prev2;

        int temp = prev2;

        prev2 = current;
        prev1 = temp;
    }

    return current;
}

int main()
{

    int n = 5;
    cout << climbingStairs(n);
    return 0;
}