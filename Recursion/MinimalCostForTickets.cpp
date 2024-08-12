#include <iostream>
#include <vector>
using namespace std;

int minCostTickets_helper(vector<int> &days, vector<int> &costs, int i)
{
    if (i >= days.size())
        return 0;

    int cost1 = costs[0] + minCostTickets_helper(days, costs, i + 1);
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= passEndDay)
        j++;

    int cost7 = costs[1] + minCostTickets_helper(days, costs, j);

    passEndDay = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= passEndDay)
        j++;
    int cost30 = costs[2] + minCostTickets_helper(days, costs, j);
    return min(cost1, min(cost7, cost30));
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return minCostTickets_helper(days, costs, 0);
}

int main()
{

    return 0;
}