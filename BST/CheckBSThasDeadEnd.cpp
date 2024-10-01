#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *right, *left;
};

class Solution
{
public:
    void func(Node *root, unordered_map<int, bool> &visited, bool &ans)
    {
        if (root == 0)
            return;
        visited[root->data] = 1;
        if (root->left == 0 && root->right == 0)
        {
            int succOfX = root->data + 1;
            int predeOfX = root->data - 1 == 0 ? root->data : root->data - 1;
            if (visited.find(succOfX) != visited.end() && visited.find(predeOfX) != visited.end())
            {
                ans = true;
                return;
            }
        }

        func(root->left, visited, ans);
        func(root->right, visited, ans);
    }

    bool isDeadEnd(Node *root)
    {
        bool ans = false;
        unordered_map<int, bool> visited;
        func(root, visited, ans);
        return ans;
    }
};

int main()
{

    return 0;
}