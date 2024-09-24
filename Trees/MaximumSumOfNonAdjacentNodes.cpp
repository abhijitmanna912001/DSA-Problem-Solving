#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    pair<int, int> getMax_helper(Node *root)
    {
        if (!root)
            return {0, 0};
        auto left = getMax_helper(root->left);
        auto right = getMax_helper(root->right);

        int a = root->data + left.second + right.second;
        int b = max(left.first, left.second) + max(right.first, right.second);
        return {a, b};
    }

    int getMaxSum(Node *root)
    {
        auto ans = getMax_helper(root);
        return max(ans.first, ans.second);
    }
};

int main()
{

    return 0;
}