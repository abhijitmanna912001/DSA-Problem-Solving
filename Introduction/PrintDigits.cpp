#include <iostream>
using namespace std;

void printAllDigits(int n)
{
    while (n > 0)
    {
        int onesDigit = n % 10;
        cout << "Digit: " << onesDigit << endl;
        n /= 10;
    }
}

int main()
{
    int n;
    cout << "Enter Number to see its digits" << endl;
    cin >> n;
    printAllDigits(n);
    return 0;
}