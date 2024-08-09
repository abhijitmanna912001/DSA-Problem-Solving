#include <iostream>
using namespace std;

int nthFibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int ans = nthFibonacci(n - 1) + nthFibonacci(n - 2);
    return ans;
}

int main()
{
    cout << nthFibonacci(9) << endl;
    return 0;
}