#include <iostream>
using namespace std;

int main()
{

    int num = 2365;
    int ans;

    while (num != 0)
    {
        cout << num % 10;
        num = num / 10;
    }
    cout << ans;

    return 0;
}