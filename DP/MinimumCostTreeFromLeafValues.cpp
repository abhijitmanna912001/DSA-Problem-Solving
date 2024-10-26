#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class Solution
{
public:
    // M4- Stack Based Approach
    int mctFromLeafValues(vector<int> &arr)
    {
        int result = 0;
        stack<int> st;

        st.push(INT_MAX);

        for (int num : arr)
        {
            while (st.top() <= num)
            {
                int mid = st.top();
                st.pop();
                result += mid * min(st.top(), num);
            }
            st.push(num);
        }

        while (st.size() > 2)
        {
            int mid = st.top();
            st.pop();
            result += mid * st.top();
        }

        return result;
    }

    // M3- Bottom Up Approach
    int solveUsingTabu(vector<int> &arr, map<pair<int, int>, int> &maxi)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
        for (int start_idx = n; start_idx >= 0; start_idx--)
        {
            for (int end_idx = 0; end_idx <= n - 1; end_idx++)
            {
                if (start_idx >= end_idx)
                    continue;
                int ans = INT_MAX;
                for (int i = start_idx; i < end_idx; i++)
                    ans = min(ans, (maxi[{start_idx, i}] * maxi[{i + 1, end_idx}]) + dp[start_idx][i] + dp[i + 1][end_idx]);
                dp[start_idx][end_idx] = ans;
            }
        }

        return dp[0][n - 1];
    }

    int mctFromLeafValues(vector<int> &arr)
    {
        map<pair<int, int>, int> maxi;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++)
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }

        int ans = solveUsingTabu(arr, maxi);
        return ans;
    }

    // M2- Top Down Approach
    int solveUsingMemo(vector<int> &arr, map<pair<int, int>, int> &maxi, int start, int end, vector<vector<int>> &dp)
    {
        if (start >= end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int ans = INT_MAX;
        for (int i = start; i < end; i++)
            ans = min(ans, (maxi[{start, i}] * maxi[{i + 1, end}]) + solveUsingMemo(arr, maxi, start, i, dp) + solveUsingMemo(arr, maxi, i + 1, end, dp));
        dp[start][end] = ans;
        return dp[start][end];
    }

    int mctFromLeafValues(vector<int> &arr)
    {
        map<pair<int, int>, int> maxi;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++)
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }

        int start = 0, end = n - 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = solveUsingMemo(arr, maxi, start, end, dp);
        return ans;
    }

    // M1: Recursion Approach
    int solveUsingRecursion(vector<int> &arr, map<pair<int, int>, int> &maxi, int start, int end)
    {
        if (start >= end)
            return 0;

        int ans = INT_MAX;
        for (int i = start; i < end; i++)
            ans = min(ans, (maxi[{start, i}] * maxi[{i + 1, end}]) + solveUsingRecursion(arr, maxi, start, i) + solveUsingRecursion(arr, maxi, i + 1, end));
        return ans;
    }

    int mctFromLeafValues(vector<int> &arr)
    {
        map<pair<int, int>, int> maxi;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++)
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }

        int start = 0, end = n - 1;
        int ans = solveUsingRecursion(arr, maxi, start, end);
        return ans;
    }
};

int main()
{

    return 0;
}