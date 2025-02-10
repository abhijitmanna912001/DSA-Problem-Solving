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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int ans = 0;
    void pathFromOneRoot(TreeNode *root, int sum)
    {
        if (!root)
            return;
        if (sum == root->val)
            ans++;
        pathFromOneRoot(root->left, sum - root->val);
        pathFromOneRoot(root->right, sum - root->val);
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        if (root)
        {
            pathFromOneRoot(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int ans = 0;
    unordered_map<long long, int> prefixSumFreq;
    void dfs(Node *root, long long currSum, int k)
    {
        if (!root)
            return;

        currSum += root->data;

        if (prefixSumFreq.find(currSum - k) != prefixSumFreq.end())
            ans += prefixSumFreq[currSum - k];

        prefixSumFreq[currSum]++;

        dfs(root->left, currSum, k);
        dfs(root->right, currSum, k);

        prefixSumFreq[currSum]--;
    }

    int sumK(Node *root, int k)
    {
        prefixSumFreq[0] = 1;
        dfs(root, 0, k);
        return ans;
    }
};

int main()
{

    return 0;
}