#include <iostream>
using namespace std;

void clearIthBit(int &n, int i)
{
    int mask = ~(1 << i);
    n = n & mask;
}

void updateIthBit(int n, int i, int target)
{
    clearIthBit(n, i);
    int mask = target << i;
    n = n | mask;
    cout << "Updated number: " << n << endl;
}

int main()
{
    int n = 10, i = 3, target = 0;
    updateIthBit(n, i, target);
    return 0;
}