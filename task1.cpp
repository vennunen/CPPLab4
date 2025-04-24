#include <iostream>
#include <iomanip> // for std::setprecision
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload / operator
    Complex operator/(const Complex &other) const
    {
        double denom = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denom;
        double i = (imag * other.real - real * other.imag) / denom;
        return Complex(r, i);
    }

    // Friend function to overload << operator
    friend ostream &operator<<(ostream &os, const Complex &c);
};

// Definition of << friend function
ostream &operator<<(ostream &os, const Complex &c)
{
    os << fixed << setprecision(6);
    os << c.real;
    if (c.imag >= 0)
        os << " + " << c.imag << "i";
    else
        os << " - " << -c.imag << "i";
    return os;
}

// Main function with test cases
int main()
{
    Complex c1(4, 5), c2(2, -3);
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "Sum = " << c1 + c2 << endl;
    cout << "Difference = " << c1 - c2 << endl;
    cout << "Quotient = " << c1 / c2 << endl;
    return 0;
}
