#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // M2- Sorting
        int n = val.size();
        vector<pair<double, int>> valWtRatio(n);

        for (int i = 0; i < n; i++)
        {
            valWtRatio[i] = {(double)val[i] / wt[i], i};
        }

        sort(valWtRatio.rbegin(), valWtRatio.rend());

        double totalValue = 0.0;

        for (int i = 0; i < n && capacity > 0; i++)
        {
            int index = valWtRatio[i].second;
            int weight = wt[index];
            int value = val[index];

            if (capacity >= weight)
            {
                totalValue += value;
                capacity -= weight;
            }
            else
            {
                totalValue += (double)value * capacity / weight;
                capacity = 0;
            }
        }

        return totalValue;

        // M1- Priority Queue
        // int n = val.size();

        // priority_queue<pair<double, pair<int, int>>> pq;

        // for (int i = 0; i < n; i++)
        // {
        //     double ratio = (double)val[i] / wt[i];
        //     pq.push({ratio, {val[i], wt[i]}});
        // }

        // double totalValue = 0.0;

        // while (capacity > 0 && !pq.empty())
        // {
        //     auto top = pq.top();
        //     pq.pop();

        //     double ratio = top.first;
        //     int value = top.second.first;
        //     int weight = top.second.second;

        //     if (capacity >= weight)
        //     {
        //         totalValue += value;
        //         capacity -= weight;
        //     }
        //     else
        //     {
        //         totalValue += ratio * capacity;
        //         capacity = 0;
        //     }
        // }

        // return totalValue;
    }
};

int main()
{

    return 0;
}