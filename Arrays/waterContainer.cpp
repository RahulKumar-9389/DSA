#include <iostream>
using namespace std;

int getContainerWithMostWater(int arr[], int size)
{

    int left = 0;
    int right = size - 1;
    int containerWithMostWater = 1;

    while (left <= right)
    {
        int height = min(arr[left], arr[right]);
        int width = right - left;
        containerWithMostWater = max(containerWithMostWater, (height * width));
        if (arr[left] < arr[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return containerWithMostWater;
}

int main()
{

    int height[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Container with most water is: " << getContainerWithMostWater(height, 9);

    return 0;
}