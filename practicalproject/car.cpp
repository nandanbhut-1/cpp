#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string model;
    int year;
    float speed;

public:
    
    void setModel(string model)
    {
        this->model = model;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    void setSpeed(float speed)
    {
        this->speed = speed;
    }

    
    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    float getSpeed()
    {
        return speed;
    }
};

int main()
{
    Car c;

    
    c.setModel("Toyota");
    c.setYear(2024);
    c.setSpeed(180.5);

    
    cout << "Car Details" << endl;
    cout << "============" << endl;
    cout << "Model: " << c.getModel() << endl;
    cout << "Year: " << c.getYear() << endl;
    cout << "Speed: " << c.getSpeed() << " km/h" << endl;

    return 0;
}