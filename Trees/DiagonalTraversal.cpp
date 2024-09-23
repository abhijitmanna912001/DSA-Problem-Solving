#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Map Based Approach
void traverse(Node *root, int d, map<int, vector<int>> &mp)
{
    if (!root)
        return;
    mp[d].push_back(root->data);
    traverse(root->left, d + 1, mp);
    traverse(root->right, d, mp);
}

vector<int> diagonal(Node *root)
{
    map<int, vector<int>> mp;
    vector<int> result;
    traverse(root, 0, mp);
    for (auto &p : mp)
    {
        for (int val : p.second)
            result.push_back(val);
    }
    return result;
}

// Queue Based Approach
vector<int> diagonal2(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        while (temp)
        {
            ans.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            temp = temp->right;
        }
    }
    return ans;
}

int main()
{

    return 0;
}