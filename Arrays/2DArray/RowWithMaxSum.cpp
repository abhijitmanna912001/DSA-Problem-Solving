#include <iostream>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    vector<int> ans;
    int n = mat.size();
    int onesCount = INT_MIN;
    int rowNo = -1;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 1)
                count++;
        }

        if (count > onesCount)
        {
            onesCount = count;
            rowNo = i;
        }
    }

    ans.push_back(rowNo);
    ans.push_back(onesCount);
    return ans;
}

int main()
{

    return 0;
}