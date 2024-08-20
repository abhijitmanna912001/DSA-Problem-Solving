#include <iostream>
using namespace std;

class Person
{
public:
    void walk()
    {
        cout << "Walking" << endl;
    }
};

class Teacher : virtual public Person
{
public:
    void teach()
    {
        cout << "Teaching" << endl;
    }
};

class Researcher : virtual public Person
{
public:
    void research()
    {
        cout << "Researching" << endl;
    }
};

class Professor : public Teacher, public Researcher, virtual public Person
{
public:
    void bore()
    {
        cout << "Boring" << endl;
    }
};

int main()
{
    Professor p;
    // 1. Scope Resolution Method
    // p.Teacher::walk();
    // p.Researcher::walk();

    // 2. Virtual set
    p.walk();
    return 0;
}