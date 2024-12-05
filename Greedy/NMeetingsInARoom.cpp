#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        int n = start.size();
        vector<pair<int, int>> time;
        for (int i = 0; i < n; i++)
            time.push_back({start[i], end[i]});

        sort(time.begin(), time.end(), [](pair<int, int> a, pair<int, int> b)
             { return a.second < b.second; });
             
        int count = 1;
        int prevStart = time[0].first;
        int prevEnd = time[0].second;

        for (int i = 1; i < n; i++)
        {
            int currStart = time[i].first;
            int currEnd = time[i].second;
            if (currStart > prevEnd)
            {
                count++;
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}