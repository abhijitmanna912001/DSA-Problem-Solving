#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        int sunday = S / 7;
        int buyingDays = S - sunday;
        int totalFood = S * M;
        int ans = 0;

        if (S >= 7 && 7 * M >= 6 * N)
            return -1;

        if (totalFood % N == 0)
            ans = totalFood / N;
        else
            ans = totalFood / N + 1;

        if (ans <= buyingDays)
            return ans;

        else
            return -1;
    }
};

int main()
{

    return 0;
}