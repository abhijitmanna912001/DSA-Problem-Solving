#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int &k = n;
    int &c = n;

    cout << "n: " << n << endl;
    cout << "k: " << k << endl;
    cout << "c: " << c << endl;

    k++;
    cout << "n: " << n << endl;
    cout << "k: " << k << endl;
    cout << "c: " << c << endl;
    return 0;
}