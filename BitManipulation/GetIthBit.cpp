#include <iostream>
using namespace std;

void getIthBit(int n, int i)
{
    int mask = (1 << i);
    int ans = n & mask;
    if (ans == 0)
        cout << "bit-> 0" << endl;
    else
        cout << "bit-> 1" << endl;
}

int main()
{
    int n = 14;
    int i = 3;

    getIthBit(n, i);
    return 0;
}