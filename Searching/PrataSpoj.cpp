#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool possibleSolution(vector<int> cooksRanks, int np, int sol)
{
    int currP = 0;
    for (int i = 0; i < cooksRanks.size(); i++)
    {
        int timeTaken = 0;
        int count = 0;
        int r = cooksRanks[i];

        while (timeTaken + (count + 1) * r <= sol)
        {
            count++;
            timeTaken += count * r;
        }

        currP += count;
        if (currP >= np)
        {
            return true;
        }
    }
    return false;
}

int minimumTimeNeededToCooknpPratas(vector<int> cooksRanks, int np)
{
    int start = 0;
    int highestRank = *max_element(cooksRanks.begin(), cooksRanks.end());
    int end = highestRank * (np * (np + 1) / 2);
    int ans = end;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (possibleSolution(cooksRanks, np, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int np, nc;
        cin >> np >> nc;
        vector<int> cooksRanks(nc);
        for (int i = 0; i < nc; i++)
        {
            cin >> cooksRanks[i];
        }
        cout << minimumTimeNeededToCooknpPratas(cooksRanks, np) << endl;
    }
    return 0;
}