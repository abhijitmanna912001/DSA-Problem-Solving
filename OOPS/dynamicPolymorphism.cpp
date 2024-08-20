#include <iostream>
using namespace std;

// Base class
class Animal
{
public:
    // Virtual function to enable dynamic polymorphism
    virtual void sound() const
    {
        cout << "This is a generic animal sound." << endl;
    }

    // Non-virtual function
    void eat() const
    {
        cout << "Animal is eating." << endl;
    }
};

// Derived class - Dog
class Dog : public Animal
{
public:
    // Overriding the virtual function
    void sound() const override
    {
        cout << "The dog barks: Woof Woof!" << endl;
    }
};

// Derived class - Cat
class Cat : public Animal
{
public:
    // Overriding the virtual function
    void sound() const override
    {
        cout << "The cat meows: Meow Meow!" << endl;
    }
};

int main()
{
    Animal *animalPtr; // Base class pointer

    Dog dog;
    Cat cat;

    // Pointing to a Dog object
    animalPtr = &dog;
    animalPtr->sound(); // Calls Dog's overridden sound() method

    // Pointing to a Cat object
    animalPtr = &cat;
    animalPtr->sound(); // Calls Cat's overridden sound() method

    return 0;
}
