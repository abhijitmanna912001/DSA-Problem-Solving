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
    void solve(TreeNode *root, int targetSum, vector<vector<int>> &ans, vector<int> temp, int sum)
    {
        if (root == NULL)
            return;
        sum += root->val;
        temp.push_back(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            if (sum == targetSum)
                ans.push_back(temp);
            else
                return;
        }

        solve(root->left, targetSum, ans, temp, sum);
        solve(root->right, targetSum, ans, temp, sum);
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, targetSum, ans, temp, sum);
        return ans;
    }
};

int main()
{

    return 0;
}