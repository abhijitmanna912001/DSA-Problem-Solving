#include <iostream>
#include <cmath>
using namespace std;

int numSquareHelper(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return INT_MAX;

    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(n);
    while (i <= end)
    {
        int perfectSquare = i * i;
        int numOfPerfectSquares = numSquareHelper(n - perfectSquare);
        if (numOfPerfectSquares != INT_MAX)
            ans = min(ans, 1 + numOfPerfectSquares);
        ++i;
    }

    return ans;
}

int numSquares(int n)
{
    return numSquareHelper(n) - 1;
}

int main()
{

    return 0;
}