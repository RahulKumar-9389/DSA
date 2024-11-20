#include <iostream>
using namespace std;

int mySqrt(int x)
{
    if (x == 0)
        return 0;

    int low = 0;
    int high = x;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long ans = (long long)mid * mid;

        if (ans == x)
        {
            return mid; // Exact match, return mid
        }
        else if (ans < x)
        {
            low = mid + 1; // Search the right half
        }
        else
        {
            high = mid - 1; // Search the left half
        }
    }
    return high;
}

int main()
{

    int n;
    cout << "Enter the number: ";
    cin >> n;

    cout << "Square root of " << n << " is " << mySqrt(n);
}