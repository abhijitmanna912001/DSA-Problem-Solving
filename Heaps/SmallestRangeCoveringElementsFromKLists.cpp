#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c)
    {
        this->data = a;
        this->rowIndex = b;
        this->colIndex = c;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        priority_queue<Info *, vector<Info *>, compare> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            int element = nums[i][0];
            int row = i;
            int col = 0;
            Info *info = new Info(element, row, col);
            pq.push(info);
            maxi = max(maxi, element);
            mini = min(mini, element);
        }

        int ansStart = mini;
        int ansEnd = maxi;

        while (!pq.empty())
        {
            Info *topNode = pq.top();
            int topData = topNode->data;
            int topCol = topNode->colIndex;
            int topRow = topNode->rowIndex;

            pq.pop();

            mini = topNode->data;
            int currentDiff = ansEnd - ansStart;
            int rangeDiff = maxi - mini;

            if (rangeDiff < currentDiff)
            {
                ansStart = mini;
                ansEnd = maxi;
            }

            if (topCol + 1 < nums[topRow].size())
            {
                int newElement = nums[topRow][topCol + 1];
                maxi = max(maxi, newElement);
                Info *newInfo = new Info(newElement, topRow, topCol + 1);
                pq.push(newInfo);
            }
            else
                break;
        }

        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};

int main()
{

    return 0;
}