#include <iostream>
#include <vector>
using namespace std;

class TreeAncestor
{
public:
    vector<int> parent;
    TreeAncestor(int n, vector<int> &parent)
    {
        this->parent = parent;
    }

    int getKthAncestor(int node, int k)
    {
        while (k > 0 && node != -1)
        {
            node = parent[node];
            k--;
        }
        return node;
    }
};

int main()
{

    return 0;
}