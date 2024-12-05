#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies + N);
        int mini = 0, buy = 0, free = N - 1;

        while (buy <= free)
        {
            mini += candies[buy];
            free -= K;
            buy++;
        }

        int maxi = 0;
        buy = N - 1, free = 0;
        while (free <= buy)
        {
            maxi += candies[buy];
            free += K;
            buy--;
        }

        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};

int main()
{

    return 0;
}