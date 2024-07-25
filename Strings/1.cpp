#include <iostream>
using namespace std;

int main()
{
    string name;
    cin >> name;
    cout << "Printing name: " << name << endl;

    int index = 0;
    while (name[index] != '\0')
    {
        cout << "index: " << index << " character: " << name[index] << endl;
        index++;
    }

    return 0;
}