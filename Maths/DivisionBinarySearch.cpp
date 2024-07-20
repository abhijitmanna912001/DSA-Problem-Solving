#include <iostream>
using namespace std;

int getQuotient(int divisor, int dividend)
{
    int start = 0, end = dividend, ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid * divisor == dividend)
            return mid;
        else if (mid * divisor < dividend)
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
    int divisor = 8;
    int dividend = 57;

    int ans = getQuotient(divisor, dividend);

    if ((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0))
    {
        ans = 0 - ans;
    }

    cout << "Final Ans is: " << ans << endl;
    return 0;
}