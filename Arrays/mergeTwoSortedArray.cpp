#include <iostream>
using namespace std;

void getMergedArray(int arr1[], int arr2[], int ans[], int s1, int s2)
{

    int i = 0, j = 0, k = 0;

    while (i < s1 && j < s2)
    {
        if (arr1[i] < arr2[j])
        {
            ans[k++] = arr1[i++];
        }
        else
        {
            ans[k++] = arr2[j++];
        }
    }

    while (i < s1)
    {
        ans[k++] = arr1[i++];
    }

    while (j < s2)
    {
        ans[j++] = arr2[j++];
    }
}

int main()
{

    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[3] = {2, 4, 6};
    int ans[8];
    getMergedArray(arr1, arr2, ans, 5, 3);

    for (int i = 0; i < 8; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}