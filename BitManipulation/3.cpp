// Check even or odd

#include <iostream>
using namespace std;

// 2. Bitwise Method
bool checkEven(int n)
{
    if ((n & 1) == 0)
    {
        return true;
    }
    else
        return false;
}

// 1. Normal Method
// bool checkEven(int n)
// {
//     if (n % 2 == 0)
//     {
//         return true;
//     }
//     else
//         return false;
// }

int main()
{
    int n;
    cin >> n;

    bool isEven = checkEven(n);

    if (isEven)
    {
        cout << n << " is even no \n";
    }
    else
        cout << n << " is odd no \n";
}