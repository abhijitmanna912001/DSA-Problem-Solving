#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    // M2- Top Down Approach
    int solveByMemo(TreeNode *root, unordered_map<TreeNode *, int> &dp)
    {
        if (!root)
            return 0;

        if (dp.find(root) != dp.end())
            return dp[root];

        int robHouse = 0, notRobHouse = 0;
        robHouse += root->val;

        if (root->left)
            robHouse += solveByMemo(root->left->left, dp) + solveByMemo(root->left->right, dp);

        if (root->right)
            robHouse += solveByMemo(root->right->left, dp) + solveByMemo(root->right->right, dp);

        notRobHouse = solveByMemo(root->left, dp) + solveByMemo(root->right, dp);
        dp[root] = max(robHouse, notRobHouse);
        return dp[root];
    }

    int rob(TreeNode *root)
    {
        unordered_map<TreeNode *, int> dp;
        return solveByMemo(root, dp);
    }

    // M1- Recursive Approach - TLE
    int solveByRecur(TreeNode *root)
    {
        if (!root)
            return 0;

        int robHouse = 0, notRobHouse = 0;
        robHouse += root->val;

        if (root->left)
            robHouse += solveByRecur(root->left->left) + solveByRecur(root->left->right);

        if (root->right)
            robHouse += solveByRecur(root->right->left) + solveByRecur(root->right->right);

        notRobHouse = solveByRecur(root->left) + solveByRecur(root->right);
        return max(robHouse, notRobHouse);
    }

    int rob(TreeNode *root)
    {
        return solveByRecur(root);
    }
};

int main()
{

    return 0;
}