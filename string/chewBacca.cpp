#include <iostream>
using namespace std;

int main()
{

    string str = "97";
    string ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        int val = str[i] - '0';
        int invertVal = (9 - val);
        ans += (min(val, invertVal) + '0');
    }
    if (ans[0] == '0')
    {
        ans[0] = '9';
    }
    cout << ans << endl;
    return 0;
}