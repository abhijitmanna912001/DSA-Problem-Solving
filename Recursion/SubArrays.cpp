#include <iostream>
#include <vector>
using namespace std;

void printSubArrayHelper(vector<int> &nums, int start, int end)
{
    if (end == nums.size())
        return;

    for (int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    printSubArrayHelper(nums, start, end + 1);
}

void printSubArray(vector<int> &nums)
{
    for (int start = 0; start < nums.size(); start++)
    {
        int end = start;
        printSubArrayHelper(nums, start, end);
    }
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5};
    printSubArray(nums);
    return 0;
}