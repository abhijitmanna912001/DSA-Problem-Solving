#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

class Solution
{
public:
    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job jobs[], int n)
    {
        sort(jobs, jobs + n, cmp);
        int maxDeadline = INT_MIN;
        for (int i = 0; i < n; i++)
            maxDeadline = max(maxDeadline, jobs[i].deadline);

        vector<int> schedule(maxDeadline + 1, -1);
        int count = 0, maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            int currProfit = jobs[i].profit;
            int currJobId = jobs[i].id;
            int currDeadline = jobs[i].deadline;

            for (int k = currDeadline; k > 0; k--)
            {
                if (schedule[k] == -1)
                {
                    count++;
                    maxProfit += currProfit;
                    schedule[k] = currJobId;
                    break;
                }
            }
        }

        vector<int> ans;
        ans.push_back(count);
        ans.push_back(maxProfit);
        return ans;
    }
};

int main()
{

    return 0;
}