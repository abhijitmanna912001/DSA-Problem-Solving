#include <iostream>
#include <unordered_map>
#include <queue>
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
    TreeNode *makeNodeToParentMappingFindTargetNode(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentMap, int target)
    {
        queue<TreeNode *> q;
        TreeNode *targetNode = 0;
        q.push(root);
        parentMap[root] = 0;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front->val == target)
                targetNode = front;
            if (front->left)
            {
                q.push(front->left);
                parentMap[front->left] = front;
            }
            if (front->right)
            {
                q.push(front->right);
                parentMap[front->right] = front;
            }
        }
        return targetNode;
    }

    int burnTheTree(TreeNode *targetNode, unordered_map<TreeNode *, TreeNode *> &parentMap)
    {
        unordered_map<TreeNode *, bool> isBurnt;
        queue<TreeNode *> q;
        int time = 0;
        q.push(targetNode);
        isBurnt[targetNode] = 1;
        while (!q.empty())
        {
            int size = q.size();
            bool isFireSpreaded = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left && !isBurnt[front->left])
                {
                    q.push(front->left);
                    isBurnt[front->left] = 1;
                    isFireSpreaded = 1;
                }
                if (front->right && !isBurnt[front->right])
                {
                    q.push(front->right);
                    isBurnt[front->right] = 1;
                    isFireSpreaded = 1;
                }
                if (parentMap[front] && !isBurnt[parentMap[front]])
                {
                    q.push(parentMap[front]);
                    isBurnt[parentMap[front]] = 1;
                    isFireSpreaded = 1;
                }
            }
            if (isFireSpreaded)
                time++;
        }
        return time;
    }

    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<TreeNode *, TreeNode *> parentMap;
        TreeNode *targetNode = makeNodeToParentMappingFindTargetNode(root, parentMap, start);
        return burnTheTree(targetNode, parentMap);
    }
};

int main()
{

    return 0;
}