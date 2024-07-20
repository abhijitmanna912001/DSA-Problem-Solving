#include <iostream>
using namespace std;

int mySqrt(int x)
{
    int start = 0, end = x;
    int ans = -1;

    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        if (mid * mid == x)
            return mid;
        else if (mid * mid < x)
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return ans;
}

int main()
{
    
    return 0;
}