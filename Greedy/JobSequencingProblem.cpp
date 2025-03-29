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
    // M2- DSU NLogN complexity solution
    int findParent(int slot, vector<int>& parent) {
        if(parent[slot] == slot)
            return slot;
            
        return parent[slot] = findParent(parent[slot], parent);
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;
        
        for(int i = 0; i < n; i++)
            jobs.push_back({profit[i], deadline[i]});
            
        sort(jobs.rbegin(), jobs.rend());
        
        int maxDeadline = 0;
        for(int i = 0; i < n; i++)
            maxDeadline = max(maxDeadline, jobs[i].second);
            
        vector<int> parent(maxDeadline + 1);
        for(int i = 0; i <= maxDeadline; i++)
            parent[i] = i;
            
        int count = 0, maxProfit = 0;
        for(int i = 0; i < n; i++) {
            int currProfit = jobs[i].first;
            int currDeadline = jobs[i].second;
            
            int availableSlot = findParent(currDeadline, parent);
            if(availableSlot > 0) {
                count++;
                maxProfit += currProfit;
                parent[availableSlot] = findParent(availableSlot - 1, parent);
            }
        }
        return {count, maxProfit};
    }

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