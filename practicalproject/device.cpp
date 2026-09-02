#include <iostream>
#include <string>
using namespace std;

class Device
{
private:
    string brand;
    float powerConsumption;

public:
    
    void setBrand(string brand)
    {
        this->brand = brand;
    }

    void setPowerConsumption(float power)
    {
        this->powerConsumption = power;
    }

    
    string getBrand()
    {
        return brand;
    }

    float getPowerConsumption()
    {
        return powerConsumption;
    }

    
    virtual void display()
    {
        cout << "Brand: " << brand << endl;
        cout << "Power Consumption: "
             << powerConsumption << " W" << endl;
    }
};

class Laptop : public Device
{
public:
    void display() override
    {
        cout << "Laptop Details" << endl;
        cout << "Brand: " << getBrand() << endl;
        cout << "Power Consumption: "
             << getPowerConsumption() << " W" << endl;
        cout << "Type: Laptop" << endl;
    }
};

class Smartphone : public Device
{
public:
    void display() override
    {
        cout << "Smartphone Details" << endl;
        cout << "Brand: " << getBrand() << endl;
        cout << "Power Consumption: "
             << getPowerConsumption() << " W" << endl;
        cout << "Type: Smartphone" << endl;
    }
};

int main()
{
    Laptop laptop;
    Smartphone phone;

    laptop.setBrand("HP");
    laptop.setPowerConsumption(65);

    phone.setBrand("Samsung");
    phone.setPowerConsumption(25);

    laptop.display();

    cout << "--------------------" << endl;

    phone.display();

    return 0;
}