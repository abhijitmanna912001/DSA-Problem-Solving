#include <iostream>
using namespace std;

int x = 2; // GLOBAL VARIABLE

void fun()
{
    int x = 60;
    cout << x << endl;
    cout << ::x << endl;
}

int main()
{
    x = 4;
    int x = 20;
    cout << x << endl;
    cout << ::x << endl;

    {
        int x = 50;
        cout << x << endl;
        cout << ::x << endl;
    }
    fun();
    return 0;
}