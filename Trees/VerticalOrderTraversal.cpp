#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> mp;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            TreeNode *&node = front.first;
            auto &coordinate = front.second;
            // auto coordinate = front.second;
            int &row = coordinate.first;
            int &col = coordinate.second;
            mp[col][row].insert(node->val);
            if (node->left)
                q.push({node->left, {row + 1, col - 1}});
            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }
        for (auto it : mp)
        {
            auto &colMap = it.second;
            vector<int> vLine;
            for (auto colMapit : colMap)
            {
                auto &mset = colMapit.second;
                vLine.insert(vLine.end(), mset.begin(), mset.end());
            }
            ans.push_back(vLine);
        }
        return ans;
    }
};

// GFG Problem
class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        if (!root)
            return {};

        map<int, vector<int>> nodesAtColumn;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            Node *node = front.first;
            int col = front.second;

            nodesAtColumn[col].push_back(node->data);

            if (node->left)
                q.push({node->left, col - 1});
            if (node->right)
                q.push({node->right, col + 1});
        }

        vector<int> result;
        for (auto &column : nodesAtColumn)
        {
            result.insert(result.end(), column.second.begin(), column.second.end());
        }

        return result;
    }
};

int main()
{
    return 0;
}