#include <iostream>
using namespace std;

class Product
{
public:
    string name;
    float prize;
    int quantity;

    Product(string name, float prize, int quantity)
    {
        this->name = name;
        this->prize = prize;
        this->quantity = quantity;
    }
};

int main()
{

    Product *p1 = new Product("Phone", 12099, 10);
    cout << "Product name is : " << p1->name << endl;     // First method
    cout << "Product prize is : " << (*p1).prize << endl; // Second method
    return 0;
}