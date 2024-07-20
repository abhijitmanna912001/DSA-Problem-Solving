#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Most Optimal
vector<int> commonElements2(vector<int> &arr1, vector<int> &arr2,
                            vector<int> &arr3)
{
    int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
    vector<int> ans;
    int i, j, k;
    i = j = k = 0;

    while (i < n1 && j < n2 && k < n3)
    {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {

            if (ans.empty() || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++, j++, k++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr3[k])
            j++;
        else
            k++;
    }

    return ans;
}

vector<int> commonElements1(vector<int> &arr1, vector<int> &arr2,
                            vector<int> &arr3)
{
    int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
    vector<int> ans;
    set<int> st;
    int i, j, k;
    i = j = k = 0;

    while (i < n1 && j < n2 && k < n3)
    {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {
            st.insert(arr1[i]);
            i++, j++, k++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr3[k])
            j++;
        else
            k++;
    }

    for (auto i : st)
    {
        ans.push_back(i);
    }

    return ans;
}

int main()
{

    return 0;
}