#include <iostream>
using namespace std;

class MaxHeap
{
public:
    int *arr;
    int size;
    int total_size;

    // Constructor
    MaxHeap(int heap_size)
    {
        arr = new int[heap_size];
        size = 0;
        total_size = heap_size;
    }

    // Insert
    void insert(int val)
    {
        if (size == total_size)
        {
            cout << "Heap is overflow!";
            return;
        }

        arr[size] = val;
        int index = size;
        size++;

        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }
    }

    // print the elements of heap
    void printMaxHeap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap *h = new MaxHeap(5);
    h->insert(5);
    h->insert(4);
    h->insert(2);

    h->printMaxHeap();

    h->insert(10);
    h->printMaxHeap();
    h->insert(20);
    h->printMaxHeap();
    h->insert(1);

    return 0;
}