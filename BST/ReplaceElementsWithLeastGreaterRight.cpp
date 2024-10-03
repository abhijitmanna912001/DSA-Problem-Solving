#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(0), right(0) {};
};

class Solution
{
public:
    Node *insertAtBST(Node *root, int val, int &succ)
    {
        if (!root)
            return new Node(val);
        if (val >= root->data)
            root->right = insertAtBST(root->right, val, succ);
        else
        {
            succ = root->data;
            root->left = insertAtBST(root->left, val, succ);
        }
        return root;
    }

    vector<int>
    findLeastGreater(vector<int> &arr, int n)
    {
        vector<int> ans(arr.size(), -1);
        Node *root = 0;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int succ = -1;
            root = insertAtBST(root, arr[i], succ);
            ans[i] = succ;
        }
        return ans;
    }
};

int main()
{

    return 0;
}