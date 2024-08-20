#include <iostream>
using namespace std;

class Singleton
{
private:
    // Private constructor to prevent direct object creation
    Singleton()
    {
        cout << "Singleton instance created" << endl;
    }

    // Static instance pointer
    static Singleton *instance;

public:
    // Deleted copy constructor and assignment operator to prevent copies
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

    // Static method to provide global access to the instance
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage()
    {
        cout << "Hello from Singleton!" << endl;
    }
};

// Initialize static member of class Singleton
Singleton *Singleton::instance = nullptr;

int main()
{
    // Can't do this: Singleton obj; // Error: constructor is private

    // Instead, use the getInstance method to access the instance
    Singleton *s1 = Singleton::getInstance();
    s1->showMessage();

    // This will return the same instance
    Singleton *s2 = Singleton::getInstance();
    s2->showMessage();

    // Both s1 and s2 point to the same instance
    cout << "Are s1 and s2 the same instance? " << (s1 == s2) << endl;

    return 0;
}
