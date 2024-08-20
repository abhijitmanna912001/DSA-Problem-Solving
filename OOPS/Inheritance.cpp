#include <iostream>
using namespace std;

class Bird
{
public:
    int age, weight;
    int noLegs;
    string color;

    void eat()
    {
        cout << "Bird is eating" << endl;
    }

    void fly()
    {
        cout << "Bird is flying" << endl;
    }
};

class Sparrow : public Bird
{
public:
    Sparrow(int age, int weight, string color, int noLegs)
    {
        this->age = age;
        this->weight = weight;
        this->color = color;
        this->noLegs = noLegs;
    }
    void grassing()
    {
        cout << "Sparrow is grassing" << endl;
    }
};

class Peigon : public Bird
{
    void guttering()
    {
        cout << "Peigon is guttering" << endl;
    }
};

class Parrot : public Bird
{
    void speaking()
    {
        cout << "Parrot is speaking" << endl;
    }
};

int main()
{
    Sparrow s(1, 1, "brown", 2);
    cout << s.color << endl;
    return 0;
}