#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isPossibleSol(vector<long long int> treeHeights, long long int m, long long int n, long long int sol)
{
    long long woodCollected = 0;
    for (long long int i = 0; i < n; i++)
    {
        if (treeHeights[i] > sol)
            woodCollected += treeHeights[i] - sol;
    }
    return woodCollected >= m;
}

long long int solution(vector<long long int> treeHeights, long long int m, long long int n)
{
    long long int start = 0;
    long long int end = *max_element(treeHeights.begin(), treeHeights.end());
    long long int ans = 0;

    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        if (isPossibleSol(treeHeights, m, n, mid))
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
    long long int m, n, treeHeight;
    vector<long long int> treeHeights;
    cin >> n >> m;

    for (long long int i = 0; i < n; i++)
    {
        cin >> treeHeight;
        treeHeights.push_back(treeHeight);
    }

    cout << solution(treeHeights, m, n) << endl;
    return 0;
}