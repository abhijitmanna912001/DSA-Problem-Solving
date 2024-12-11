#include <iostream>
using namespace std;

void clearLastIthBit(int n, int i)
{
    int mask = (-1 << i);
    n = n & mask;
    cout << "Updated number: " << n << endl;
}

int main()
{
    int n = 15, i = 2;
    clearLastIthBit(n, i);
    return 0;
}