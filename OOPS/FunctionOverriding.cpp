#include <iostream>
using namespace std;

// Base class
class Animal
{
public:
    // Virtual function to allow overriding in derived classes
    virtual void sound() const
    {
        cout << "This is a generic animal sound." << endl;
    }
};

// Derived class - Dog
class Dog : public Animal
{
public:
    // Overriding the sound function of the base class
    void sound() const override
    {
        cout << "The dog barks: Woof Woof!" << endl;
    }
};

// Derived class - Cat
class Cat : public Animal
{
public:
    // Overriding the sound function of the base class
    void sound() const override
    {
        cout << "The cat meows: Meow Meow!" << endl;
    }
};

int main()
{
    Animal *animal;

    Dog dog;
    Cat cat;

    // Base class pointer pointing to derived class object
    animal = &dog;
    animal->sound(); // Calls Dog's sound function

    animal = &cat;
    animal->sound(); // Calls Cat's sound function

    return 0;
}
