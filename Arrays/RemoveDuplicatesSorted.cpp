#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 0, j = 0;

    while (i < nums.size())
    {
        if (nums[i] == nums[j])
            ++i;
        else
            nums[++j] = nums[i++];
    }
    return j + 1;
}

int main()
{

    return 0;
}