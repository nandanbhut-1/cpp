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

    virtual float calculateDiscount()
    {
        return 0;
    }

    virtual void display()
    {
        cout << "Brand: " << brand << endl;
        cout << "Power: " << powerConsumption << " W" << endl;
    }

    virtual ~Device() {}
};

class Laptop : public Device
{
public:
    float calculateDiscount() override
    {
        if (getPowerConsumption() > 50)
            return 10;
        else
            return 5;
    }

    void display() override
    {
        cout << "Laptop: " << getBrand() << endl;
        cout << "Power: " << getPowerConsumption() << " W" << endl;
    }
};

class Smartphone : public Device
{
public:
    float calculateDiscount() override
    {
        if (getPowerConsumption() > 50)
            return 10;
        else
            return 5;
    }

    void display() override
    {
        cout << "Smartphone: " << getBrand() << endl;
        cout << "Power: " << getPowerConsumption() << " W" << endl;
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

    
    Device* devices[2];

    devices[0] = &laptop;
    devices[1] = &phone;

    cout << "Device Discount Details" << endl;
    cout << "========================" << endl;

    for (int i = 0; i < 2; i++)
    {
        devices[i]->display();

        cout << "Discount: "
             << devices[i]->calculateDiscount()
             << "%" << endl;

        cout << "------------------------" << endl;
    }

    return 0;
}