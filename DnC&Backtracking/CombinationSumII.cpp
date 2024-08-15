#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void combinationSum_helper(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &ans, int index)
{
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    if (target < 0)
        return;

    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
            continue;

        v.push_back(candidates[i]);
        combinationSum_helper(candidates, target - candidates[i], v, ans, i + 1);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> v;
    combinationSum_helper(candidates, target, v, ans, 0);
    set<vector<int>> st;
    for (auto e : ans)
    {
        st.insert(e);
    }
    ans.clear();
    for (auto e : st)
    {
        ans.push_back(e);
    }

    return ans;
}

int main()
{

    return 0;
}