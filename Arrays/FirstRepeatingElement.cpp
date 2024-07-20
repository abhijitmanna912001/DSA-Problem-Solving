#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int firstRepeated2(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] > 1)
        {
            return i + 1;
        }
    }

    return -1;
}

int firstRepeated(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        bool isRepeated = false;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                isRepeated = true;
                return i + 1;
            }
        }
    }
    return -1;
}

int main()
{
    return 0;
}