#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // M4- Space Optimised 2D DP
    vector<TreeNode *> buildTrees(int start, int end, vector<vector<int>> &roots)
    {
        vector<TreeNode *> result;
        if (start > end)
        {
            result.push_back(nullptr);
            return result;
        }

        for (int rootVal = start; rootVal <= end; rootVal++)
        {
            vector<TreeNode *> leftTrees = buildTrees(start, rootVal - 1, roots);
            vector<TreeNode *> rightTrees = buildTrees(rootVal + 1, end, roots);

            for (TreeNode *left : leftTrees)
            {
                for (TreeNode *right : rightTrees)
                {
                    TreeNode *root = new TreeNode(rootVal);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};

        vector<vector<int>> roots(n + 1, vector<int>(n + 1, 0));

        for (int len = 1; len <= n; ++len)
        {
            for (int start = 1; start <= n - len + 1; ++start)
            {
                int end = start + len - 1;
                roots[start][end] = start;
            }
        }

        return buildTrees(1, n, roots);
    }

    // M3- Bottom Up Approach
    vector<TreeNode *> allPossibleBSTTabular(int n)
    {
        vector<vector<vector<TreeNode *>>> dp(n + 1, vector<vector<TreeNode *>>(n + 1));

        // Bottom-up filling of the dp table
        for (int len = 1; len <= n; ++len)
        {
            for (int start = 1; start <= n - len + 1; ++start)
            {
                int end = start + len - 1;
                vector<TreeNode *> trees;

                for (int rootVal = start; rootVal <= end; ++rootVal)
                {
                    vector<TreeNode *> leftSubtrees = (rootVal == start) ? vector<TreeNode *>{nullptr} : dp[start][rootVal - 1];
                    vector<TreeNode *> rightSubtrees = (rootVal == end) ? vector<TreeNode *>{nullptr} : dp[rootVal + 1][end];

                    for (auto left : leftSubtrees)
                    {
                        for (auto right : rightSubtrees)
                        {
                            TreeNode *root = new TreeNode(rootVal);
                            root->left = left;
                            root->right = right;
                            trees.push_back(root);
                        }
                    }
                }
                dp[start][end] = trees;
            }
        }
        return dp[1][n];
    }

    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return allPossibleBSTTabular(n);
    }

    // M2- Top Down Approach
    vector<TreeNode *> allPossibleBSTMemo(int start, int end, vector<vector<vector<TreeNode *>>> &dp)
    {
        if (start > end)
            return {nullptr};
        if (start == end)
            return {new TreeNode(start)};

        if (!dp[start][end].empty())
            return dp[start][end];

        vector<TreeNode *> ans;
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> left = allPossibleBSTMemo(start, i - 1, dp);
            vector<TreeNode *> right = allPossibleBSTMemo(i + 1, end, dp);
            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        dp[start][end] = ans;
        return dp[start][end];
    }

    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        vector<vector<vector<TreeNode *>>> dp(n + 1, vector<vector<TreeNode *>>(n + 1));
        return allPossibleBSTMemo(1, n, dp);
    }

    // M1- Recursive Approach
    vector<TreeNode *> allPossibleBSTRecur(int start, int end)
    {
        if (start > end)
            return {0};
        if (start == end)
            return {new TreeNode(start)};

        vector<TreeNode *> ans;
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> left = allPossibleBSTRecur(start, i - 1);
            vector<TreeNode *> right = allPossibleBSTRecur(i + 1, end);
            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return allPossibleBSTRecur(1, n);
    }
};
