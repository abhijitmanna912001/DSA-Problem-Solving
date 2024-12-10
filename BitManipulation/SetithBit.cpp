#include <iostream>
using namespace std;

void setIthBit(int n, int i)
{
    int mask = (1 << i);
    n = n | mask;
    cout << "Updated No: " << n << endl;
}

int main()
{
    int n = 10;
    int i = 2;

    setIthBit(n, i);
    return 0;
}