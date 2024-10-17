#include <iostream>
using namespace std;

class Vector
{
public:
    int size;
    int capacity;
    int *arr;

    Vector()
    {
        size = 0;
        capacity = 1;
        arr = new int[1];
    }

    void add(int element)
    {
        if (size == capacity)
        {
            capacity *= 2;
            int *arr2 = new int[capacity];

            for (int i = 0; i < size; i++)
            {
                arr2[i] = arr[i];
            }
            arr = arr2;
        }
        arr[size++] = element;
    }

    void remove()
    {
        if (size == 0)
        {
            cout << "Array is empty!" << endl;
        }
        size--;
    }

    void print()
    {
        if (size == 0)
        {
            cout << "Array is empty!" << endl;
        }

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int get(int idx)
    {
        if (size == 0)
        {
            cout << "Array is empty!" << endl;
            return -1;
        }

        if (idx >= size || idx < 0)
        {
            cout << "Invalid index!" << endl;
            return -1;
        }
        return arr[idx];
    }
};

int main()
{

    Vector v1;
    for (int i = 0; i < 5; i++)
    {
        v1.add(i);
    }
    v1.print();
    cout << "Size of the array is: " << v1.size << endl;
    cout << "Capacity of the array is: " << v1.capacity << endl;
    cout << endl;

    cout << "After removing " << endl;
    v1.remove();
    v1.print();
    cout << "After removing size of the array is: " << v1.size << endl;
    cout << "After removing capacity of the array is: " << v1.capacity << endl;

    cout << v1.get(2);

    return 0;
}