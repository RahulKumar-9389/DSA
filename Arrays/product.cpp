#include <iostream>
#include <vector>
using namespace std;

int product(vector<int> &arr)
{

    int prod = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        prod *= arr[i];
    }
    return prod;
}

int main()
{

    vector<int> arr = {2, 4, 5, 8, 1};

    cout << "Product of the elements is: " << product(arr);

    return 0;
}