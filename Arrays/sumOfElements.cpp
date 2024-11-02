#include <iostream>
#include <vector>
using namespace std;

int sumOfElements(vector<int> &arr)
{
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

int main()
{

    vector<int> arr = {2, 5, 7, 10};
    cout << "Sum of the elements is: " << sumOfElements(arr);
    return 0;
}