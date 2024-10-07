#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solveForMedian(double &median, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int element)
{
    if (maxi.size() == mini.size())
    {
        if (element > median)
        {
            mini.push(element);
            median = mini.top();
        }

        else
        {
            maxi.push(element);
            median = maxi.top();
        }
    }
    else if (maxi.size() == mini.size() + 1)
    {
        if (element > median)
            mini.push(element);
        else
        {
            int maxTop = maxi.top();
            maxi.pop();
            mini.push(maxTop);
            maxi.push(element);
        }

        median = (mini.top() + maxi.top()) / 2.0;
    }
    else if (mini.size() == maxi.size() + 1)
    {
        if (element < median)
            maxi.push(element);
        else
        {
            int minTop = mini.top();
            mini.pop();
            maxi.push(minTop);
            mini.push(element);
        }

        median = (mini.top() + maxi.top()) / 2.0;
    }
}

// GFG Solution
class Solution
{
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    double median = 0.0;

public:
    void insertHeap(int &x)
    {

        if (maxi.empty() || x <= maxi.top())
        {
            maxi.push(x);
        }
        else
        {
            mini.push(x);
        }

        balanceHeaps();
    }

    void balanceHeaps()
    {
        if (maxi.size() > mini.size() + 1)
        {
            mini.push(maxi.top());
            maxi.pop();
        }
        else if (mini.size() > maxi.size())
        {
            maxi.push(mini.top());
            mini.pop();
        }
    }

    double getMedian()
    {
        if (maxi.size() > mini.size())
        {
            return maxi.top();
        }
        else
        {
            return (maxi.top() + mini.top()) / 2.0;
        }
    }
};

// LeetCode Solution
class MedianFinder
{
public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    double median = 0.0;
    MedianFinder() {}

    void addNum(int num)
    {
        if (maxi.size() == mini.size())
        {
            if (num > median)
            {
                mini.push(num);
                median = mini.top();
            }
            else
            {
                maxi.push(num);
                median = maxi.top();
            }
        }
        else if (maxi.size() > mini.size())
        {
            if (num > median)
            {
                mini.push(num);
            }
            else
            {
                int maxTop = maxi.top();
                maxi.pop();
                mini.push(maxTop);
                maxi.push(num);
            }
            median = (mini.top() + maxi.top()) / 2.0;
        }
        else
        {
            if (num < median)
            {
                maxi.push(num);
            }
            else
            {
                int minTop = mini.top();
                mini.pop();
                maxi.push(minTop);
                mini.push(num);
            }
            median = (mini.top() + maxi.top()) / 2.0;
        }
    }

    double findMedian()
    {
        return median;
    }
};

int main()
{
    int arr[] = {5, 15, 1, 3};
    int n = 4;
    double median = 0;

    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        solveForMedian(median, maxi, mini, element);
        cout << "Median found: " << median << endl;
    }

    return 0;
}