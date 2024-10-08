#include <iostream>
using namespace std;

void tower(int n, char s, char h, char d)
{
    if (n == 0)
        return;

    tower(n - 1, s, d, h);
    cout << s << " -> " << d << endl;
    tower(n - 1, h, s, d);
    return;
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    // declare source, helper, destination
    char source = 'A';
    char helper = 'B';
    char destination = 'C';
    tower(n, source, helper, destination);
    return 0;
}