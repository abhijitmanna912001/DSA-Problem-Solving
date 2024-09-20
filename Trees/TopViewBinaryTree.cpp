#include <iostream>
#include <vector>
#include <map>
#include <queue>
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
    vector<int> topView(Node *root)
    {
        map<int, int> hdNodemap;
        queue<pair<Node *, int>> q;
        vector<int> result;

        if (root == NULL)
            return result;
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();

            Node *frontNode = temp.first;
            int hd = temp.second;

            if (hdNodemap.find(hd) == hdNodemap.end())
                hdNodemap[hd] = frontNode->data;

            if (frontNode->left != NULL)
                q.push(make_pair(frontNode->left, hd - 1));

            if (frontNode->right != NULL)
                q.push(make_pair(frontNode->right, hd + 1));
        }

        for (auto it : hdNodemap)
            result.push_back(it.second);

        return result;
    }
};

int main()
{

    return 0;
}