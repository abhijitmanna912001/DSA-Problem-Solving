#include <iostream>
using namespace std;

// Base class
class Animal
{
public:
    void eat()
    {
        cout << "Animal is eating." << endl;
    }

    virtual void sound() const
    {
        cout << "Some generic animal sound." << endl;
    }
};

// Derived class - Dog
class Dog : public Animal
{
public:
    void eat()
    {
        cout << "Dog is eating." << endl;
    }

    void sound() const override
    {
        cout << "Dog barks: Woof Woof!" << endl;
    }

    void fetch()
    {
        cout << "Dog is fetching the ball." << endl;
    }
};

int main()
{
    Dog myDog;         // Creating an object of the derived class
    Animal *animalPtr; // Base class pointer

    // Upcasting: Pointing the base class pointer to the derived class object
    animalPtr = &myDog;

    // Accessing base class method
    animalPtr->eat(); // Outputs: "Animal is eating."

    // Accessing overridden method via upcasting
    animalPtr->sound(); // Outputs: "Dog barks: Woof Woof!"

    // Trying to access derived class-specific method (will not compile)
    // animalPtr->fetch(); // Error: 'class Animal' has no member named 'fetch'

    return 0;
}
