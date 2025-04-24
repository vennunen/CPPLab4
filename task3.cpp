#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string model;
    int year;
    double price;

public:
    Car(string m = "Unknown", int y = 0, double p = 0.0) : model(m), year(y), price(p)
    {
        cout << "Car Constructor: " << model << " (" << year << ") - $" << price << endl;
    }

    ~Car()
    {
        cout << "Car Destructor: " << model << " destroyed" << endl;
    }

    void display() const
    {
        cout << "Model: " << model << ", Year: " << year << ", Price: $" << price << endl;
    }

    void input()
    {
        cout << "Enter model: ";
        getline(cin, model);
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter price: ";
        cin >> price;
        cin.ignore(); // Clear newline left in input buffer
    }
};

class CarCollection
{
private:
    Car *cars;
    int size;

public:
    CarCollection()
    {
        cout << "How many cars do you want to enter? ";
        cin >> size;
        cin.ignore(); // Clear newline for getline use

        cars = new Car[size];

        for (int i = 0; i < size; ++i)
        {
            cout << "\nEnter model for car " << i + 1 << ": ";
            cars[i].input();
        }

        cout << "CarCollection initialized with " << size << " cars\n";
    }

    ~CarCollection()
    {
        delete[] cars;
        cout << "CarCollection destroyed" << endl;
    }

    void displayCars() const
    {
        cout << "\n--- Car Collection ---\n";
        for (int i = 0; i < size; ++i)
        {
            cars[i].display();
        }
    }
};

int main()
{
    {
        CarCollection collection;
        collection.displayCars();
    } // CarCollection and Cars go out of scope here, triggering destructors

    return 0;
}
