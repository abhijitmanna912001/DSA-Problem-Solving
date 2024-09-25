#include <iostream>
#include <vector>
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
    vector<TreeNode *> ans;
    unordered_map<string, int> subTreeMap;
    string preOrder(TreeNode *root)
    {
        if (!root)
            return "N";
        string curr = to_string(root->val);
        string left = preOrder(root->left);
        string right = preOrder(root->right);

        string s = curr + "," + left + "," + right;
        if (subTreeMap.find(s) != subTreeMap.end())
        {
            if (subTreeMap[s] == 1)
                ans.push_back(root);
            subTreeMap[s]++;
        }
        else
            subTreeMap[s] = 1;
        return s;
    }
    
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        preOrder(root);
        return ans;
    }
};

int main()
{

    return 0;
}