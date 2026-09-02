#include <iostream>
using namespace std;

// Abstract class
class Animal
{
public:
    // Pure virtual functions
    virtual void makeSound() = 0;
    virtual void move() = 0;

    virtual ~Animal() {}
};

class Lion : public Animal
{
public:
    void makeSound() override
    {
        cout << "Lion says: Roar!" << endl;
    }

    void move() override
    {
        cout << "Lion moves by walking and running." << endl;
    }
};

class Fish : public Animal
{
public:
    void makeSound() override
    {
        cout << "Fish makes no sound." << endl;
    }

    void move() override
    {
        cout << "Fish moves by swimming." << endl;
    }
};

int main()
{
    Lion lion;
    Fish fish;

    // Array of Animal pointers
    Animal* animals[2];

    animals[0] = &lion;
    animals[1] = &fish;

    cout << "Animal Details" << endl;
    cout << "====================" << endl;

    for (int i = 0; i < 2; i++)
    {
        animals[i]->makeSound();
        animals[i]->move();

        cout << "--------------------" << endl;
    }

    return 0;
}