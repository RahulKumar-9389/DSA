#include <iostream>
using namespace std;

int main()
{

    int n = 4518;
    int ans = 0;

    while (n > 0)
    {
        int last_digit = n % 10;
        ans = ans * 10 + last_digit;
        n = n / 10;
    }

    cout << ans;

    return 0;
}