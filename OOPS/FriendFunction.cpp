#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    // Constructor to initialize complex number
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Friend function declaration
    friend Complex addComplex(const Complex &c1, const Complex &c2);

    // Function to display complex number
    void display() const
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Friend function definition
Complex addComplex(const Complex &c1, const Complex &c2)
{
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

int main()
{
    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "Complex number 1: ";
    c1.display();

    cout << "Complex number 2: ";
    c2.display();

    // Use friend function to add c1 and c2
    Complex c3 = addComplex(c1, c2);

    cout << "Sum of c1 and c2: ";
    c3.display();

    return 0;
}
