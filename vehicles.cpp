#include <iostream>
#include <stdlib.h>

using namespace std;


class Vehicle
{
private:
    static int totalVehicles;
    int totalCount;

public:
    string vehicleID, manufacturer, model, year;

    Vehicle(string vehicleID, string manufacturer, string model, string year)
    {
        this->vehicleID = vehicleID;
        this->manufacturer = manufacturer;
        this->model = model;
        this->year = year;

        Vehicle::totalVehicles++;
    }

    virtual void display()
    {
        cout << "Vehicle ID : " << vehicleID << endl;
        cout << "Manufacturer : " << manufacturer << endl;
        cout << "Model : " << model << endl;
        cout << "Year : " << year << endl;
    }

    void setTotalCount()
    {
        totalCount = Vehicle::totalVehicles;
    }

    int getTotalCount()
    {
        return totalCount;
    }

    virtual ~Vehicle()
    {
    }
};

int Vehicle::totalVehicles = 0;

// Car Class
class Car : public Vehicle
{
public:
    string fuelType;

    Car(string vehicleID, string manufacturer, string model,
        string year, string fuelType)
        : Vehicle(vehicleID, manufacturer, model, year)
    {
        this->fuelType = fuelType;
    }

    void display()
    {
        Vehicle::display();
        cout << "Fuel Type : " << fuelType << endl;
    }
};


class ElectricCar : public Car
{
public:
    string batteryCapacity;

    ElectricCar(string vehicleID, string manufacturer, string model,
                string year, string fuelType, string batteryCapacity)
        : Car(vehicleID, manufacturer, model, year, fuelType)
    {
        this->batteryCapacity = batteryCapacity;
    }

    void display()
    {
        Car::display();
        cout << "Battery : " << batteryCapacity << endl;
    }
};


class Aircraft : public Vehicle
{
public:
    string flightRange;

    Aircraft(string vehicleID, string manufacturer, string model,
             string year, string flightRange)
        : Vehicle(vehicleID, manufacturer, model, year)
    {
        this->flightRange = flightRange;
    }

    void display()
    {
        Vehicle::display();
        cout << "Flight Range : " << flightRange << endl;
    }
};


class FlyingCar : public Car
{
public:
    string flightRange;

    FlyingCar(string vehicleID, string manufacturer, string model,
              string year, string fuelType, string flightRange)
        : Car(vehicleID, manufacturer, model, year, fuelType)
    {
        this->flightRange = flightRange;
    }

    void display()
    {
        Car::display();
        cout << "Flight Range : " << flightRange << endl;
    }
};


class SportsCar : public ElectricCar
{
public:
    string topSpeed;

    SportsCar(string vehicleID, string manufacturer, string model, string year, string fuelType, string batteryCapacity, string topSpeed)
        : ElectricCar(vehicleID, manufacturer, model, year, fuelType, batteryCapacity)
    {
        this->topSpeed = topSpeed;
    }

    void display()
    {
        ElectricCar::display();
        cout << "Top Speed  : " << topSpeed << endl;
    }
};


class Sedan : public Car
{
public:
    Sedan(string vehicleID, string manufacturer, string model, string year, string fuelType)
        : Car(vehicleID, manufacturer, model, year, fuelType)
    {
    }

    void display()
    {
        Car::display();
        cout << "Type : Sedan" << endl;
    }
};


class SUV : public Car
{
public:
    SUV(string vehicleID, string manufacturer, string model,
        string year, string fuelType)
        : Car(vehicleID, manufacturer, model, year, fuelType)
    {
    }

    void display()
    {
        Car::display();
        cout << "Type : SUV" << endl;
    }
};


class VehicleRegistry
{
public:
    Vehicle *v[100];
    int count;

    VehicleRegistry()
    {
        count = 0;
    }

    void adding()
    {
        int type;

        cout << "\nSelect Vehicle Type\n";
        cout << "1. Car\n";
        cout << "2. Electric Car\n";
        cout << "3. Aircraft\n";
        cout << "4. Flying Car\n";
        cout << "5. Sports Car\n";
        cout << "6. Sedan\n";
        cout << "7. SUV\n";
        cout << "Enter choice: ";
        cin >> type;

        string id, manufacturer, model, year, fuelType;
        string batteryCapacity, flightRange, topSpeed;

        cout << "Enter Vehicle ID: ";
        cin >> id;

        cout << "Enter Manufacturer: ";
        cin >> manufacturer;

        cout << "Enter Model: ";
        cin >> model;

        cout << "Enter Year: ";
        cin >> year;

        switch (type)
        {
        case 1:
            cout << "Enter Fuel Type: ";
            cin >> fuelType;

            v[count] = new Car(id, manufacturer, model, year, fuelType);
            count++;
            break;

        case 2:
            cout << "Enter Fuel Type: ";
            cin >> fuelType;

            cout << "Enter Battery Capacity: ";
            cin >> batteryCapacity;

            v[count] = new ElectricCar(id, manufacturer, model, year, fuelType, batteryCapacity);
            count++;
            break;

        case 3:
            cout << "Enter Flight Range: ";
            cin >> flightRange;

            v[count] = new Aircraft(id, manufacturer, model, year, flightRange);
            count++;
            break;

        case 4:
            cout << "Enter Fuel Type: ";
            cin >> fuelType;

            cout << "Enter Flight Range: ";
            cin >> flightRange;

            v[count] = new FlyingCar(id, manufacturer, model, year, fuelType, flightRange);
            count++;
            break;

        case 5:
            cout << "Enter Fuel Type: ";
            cin >> fuelType;

            cout << "Enter Battery Capacity: ";
            cin >> batteryCapacity;

            cout << "Enter Top Speed: ";
            cin >> topSpeed;

            v[count] = new SportsCar(id, manufacturer, model, year, fuelType, batteryCapacity, topSpeed);
            count++;
            break;

        case 6:
            cout << "Enter Fuel Type: ";
            cin >> fuelType;

            v[count] = new Sedan(id, manufacturer, model, year, fuelType);
            count++;
            break;

        case 7:
            cout << "Enter Fuel Type: ";
            cin >> fuelType;

            v[count] = new SUV(id, manufacturer, model, year, fuelType);
            count++;
            break;

        default:
            cout << "Invalid vehicle type!" << endl;
        }

        cout << "\nVehicle added successfully!\n";
    }

    void displaying()
    {
        if (count == 0)
        {
            cout << "\nNo vehicles available.\n";
            return;
        }

        cout << "\n========== ALL VEHICLES ==========\n";

        for (int i = 0; i < count; i++)
        {
            cout << "\nVehicle " << i + 1 << endl;
            cout << "--------------------------" << endl;

            v[i]->display();
        }
    }

    void searching()
    {
        string id;

        cout << "\nEnter Vehicle ID to search: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (v[i]->vehicleID == id)
            {
                cout << "\nVehicle Found!\n";
                cout << "--------------------------\n";

                v[i]->display();
                return;
            }
        }

        cout << "\nVehicle not found!\n";
    }

    ~VehicleRegistry()
    {
        for (int i = 0; i < count; i++)
        {
            delete v[i];
        }
    }
};

// Main
int main()
{
    VehicleRegistry data;
    int choice;

    while (true)
    {
        cout << "\n========== VEHICLE REGISTRY ==========\n";
        cout << "1. Add a vehicle\n";
        cout << "2. View all vehicles\n";
        cout << "3. Search by ID\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            data.adding();
            break;

        case 2:
            data.displaying();
            break;

        case 3:
            data.searching();
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}