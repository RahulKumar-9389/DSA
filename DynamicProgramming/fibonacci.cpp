#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n)
{
    // Handle base case
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Create a DP table to store Fibonacci numbers
    vector<int> dp(n + 1);

    // Base cases
    dp[0] = 0;
    dp[1] = 1;

    // Fill the DP table from 2 to n
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // The nth Fibonacci number
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;

    return 0;
}
