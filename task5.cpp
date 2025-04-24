#include <iostream>
#include <string>
using namespace std;

class Car
{
protected:
    string model;
    int year;
    float price;

public:
    Car() {}
    virtual ~Car()
    {
        cout << "Destroying ";
    }
    void inputBasic()
    {
        cout << "Enter model: ";
        getline(cin, model);
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter price: ";
        cin >> price;
    }
    void displayBasic() const
    {
        cout << "Model: " << model << ", Year: " << year << ", Price: $" << price;
    }
};

class ElectricCar : public Car
{
    float batterySize;

public:
    void input()
    {
        inputBasic();
        cout << "Enter battery size (kWh): ";
        cin >> batterySize;
    }
    void display() const
    {
        displayBasic();
        cout << ", Battery: " << batterySize << " kWh" << endl;
    }
    ~ElectricCar()
    {
        cout << "Electric Car: " << model << endl;
    }
};

class GasCar : public Car
{
    float fuelCapacity;

public:
    void input()
    {
        inputBasic();
        cout << "Enter fuel capacity (L): ";
        cin >> fuelCapacity;
    }
    void display() const
    {
        displayBasic();
        cout << ", Fuel: " << fuelCapacity << " L" << endl;
    }
    ~GasCar()
    {
        cout << "Gas Car: " << model << endl;
    }
};

class HybridCar : public Car
{
    float batterySize, fuelCapacity;

public:
    void input()
    {
        inputBasic();
        cout << "Enter battery size (kWh): ";
        cin >> batterySize;
        cout << "Enter fuel capacity (L): ";
        cin >> fuelCapacity;
    }
    void display() const
    {
        displayBasic();
        cout << ", Battery: " << batterySize << " kWh, Fuel: " << fuelCapacity << " L" << endl;
    }
    ~HybridCar()
    {
        cout << "Hybrid Car: " << model << endl;
    }
};

int main()
{
    int n;
    cout << "Enter total number of cars: ";
    cin >> n;
    cin.ignore(); // Clear newline after int input

    Car **fleet = new Car *[n];
    int *types = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "Car " << i + 1 << " type:\n";
        cout << "[1] Electric\n[2] Gasoline\n[3] Hybrid\n";
        cout << "Enter choice: ";
        cin >> types[i];
        cin.ignore(); // Clear newline

        if (types[i] == 1)
        {
            ElectricCar *e = new ElectricCar();
            e->input();
            fleet[i] = e;
        }
        else if (types[i] == 2)
        {
            GasCar *g = new GasCar();
            g->input();
            fleet[i] = g;
        }
        else if (types[i] == 3)
        {
            HybridCar *h = new HybridCar();
            h->input();
            fleet[i] = h;
        }
    }

    cout << "\n--- Fleet Information ---\n";
    for (int i = 0; i < n; ++i)
    {
        if (types[i] == 1)
        {
            static_cast<ElectricCar *>(fleet[i])->display();
        }
        else if (types[i] == 2)
        {
            static_cast<GasCar *>(fleet[i])->display();
        }
        else if (types[i] == 3)
        {
            static_cast<HybridCar *>(fleet[i])->display();
        }
    }

    cout << "\n--- Cleaning up fleet ---\n";
    for (int i = 0; i < n; ++i)
    {
        delete fleet[i];
    }

    delete[] fleet;
    delete[] types;

    return 0;
}
