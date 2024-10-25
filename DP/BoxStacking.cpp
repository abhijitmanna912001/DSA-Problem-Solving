#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &curr, vector<int> &prev)
    {
        if (prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2])
            return true;
        else
            return false;
    }

    int solveUsingSpaceOptimization(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();
        vector<int> curr(n + 1, 0);
        vector<int> prev(n + 1, 0);

        for (int curr_idx = n - 1; curr_idx >= 0; curr_idx--)
        {
            for (int prev_idx = curr_idx - 1; prev_idx >= -1; prev_idx--)
            {
                int include = 0;
                if (prev_idx == -1 || check(cuboids[curr_idx], cuboids[prev_idx]))
                {
                    int heightToAdd = cuboids[curr_idx][2];
                    include = heightToAdd + prev[curr_idx + 1];
                }
                int exclude = prev[prev_idx + 1];
                curr[prev_idx + 1] = max(include, exclude);
            }
            prev = curr;
        }
        return prev[0];
    }

    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &cuboid : cuboids)
            sort(cuboid.begin(), cuboid.end());

        sort(cuboids.begin(), cuboids.end());
        int ans = solveUsingSpaceOptimization(cuboids);
        return ans;
    }
};

// GFG Problem
class Solution
{
public:
    struct Box
    {
        int length, width, height;
    };

    bool static compare(Box a, Box b)
    {
        return (a.length * a.width) > (b.length * b.width);
    }

    int maxHeight(int height[], int width[], int length[], int n)
    {
        vector<Box> boxes;

        // Generate all 3 rotations of each box
        for (int i = 0; i < n; i++)
        {
            boxes.push_back({max(length[i], width[i]), min(length[i], width[i]), height[i]});
            boxes.push_back({max(width[i], height[i]), min(width[i], height[i]), length[i]});
            boxes.push_back({max(height[i], length[i]), min(height[i], length[i]), width[i]});
        }

        // Sort boxes by base area (length * width) in descending order
        sort(boxes.begin(), boxes.end(), compare);

        int m = boxes.size();
        vector<int> dp(m);

        // Initialize dp[] with heights of each box as a single-box stack
        for (int i = 0; i < m; i++)
        {
            dp[i] = boxes[i].height;
        }

        // Compute maximum stack height using DP
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (boxes[i].length < boxes[j].length && boxes[i].width < boxes[j].width)
                {
                    dp[i] = max(dp[i], dp[j] + boxes[i].height);
                }
            }
        }

        // The answer is the maximum value in dp array
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{

    return 0;
}