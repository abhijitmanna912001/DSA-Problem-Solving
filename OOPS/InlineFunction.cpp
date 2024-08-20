#include <iostream>
using namespace std;

// Inline function to calculate the square of a number
inline int square(int x)
{
    return x * x;
}

int main()
{
    int num1 = 5;
    int num2 = 10;

    // Using the inline function
    cout << "Square of " << num1 << " is " << square(num1) << endl;
    cout << "Square of " << num2 << " is " << square(num2) << endl;

    return 0;
}
