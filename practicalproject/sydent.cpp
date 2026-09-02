#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int rollNumber;

public:
    // Parameterized constructor
    Student(string name, int rollNumber)
    {
        this->name = name;
        this->rollNumber = rollNumber;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "--------------------" << endl;
    }
};

int main()
{
    // Array of Student objects
    Student students[3] = {
        Student("Rahul", 101),
        Student("Amit", 102),
        Student("Nandan", 103)
    };

    cout << "Student Details" << endl;
    cout << "====================" << endl;

    for (int i = 0; i < 3; i++)
    {
        students[i].display();
    }

    return 0;
}