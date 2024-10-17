#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int rollNo;
    float CGPA;
};

int main()
{

    Student s;
    s.name = "RahulKumar";
    s.rollNo = 58;
    s.CGPA = 7.8;

    cout << s.name;

    return 0;
}