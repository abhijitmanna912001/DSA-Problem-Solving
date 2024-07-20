#include <iostream>
#include <vector>

using namespace std;

int binarySearchApproach(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (start == end)
            return start;

        if (nums[mid] < nums[mid - 1])
            return mid - 1;
        else if (nums[mid] > nums[mid - 1])
            return mid;
        else if (nums[start] > nums[mid])
            return end = mid - 1;
        else
            return start = mid + 1;
    }
    return -1;
}

int prefixSumApproach(vector<int> &nums)
{
    vector<int> lsum(nums.size(), 0);
    vector<int> rsum(nums.size(), 0);

    for (int i = 1; i < nums.size(); ++i)
    {
        lsum[i] = lsum[i - 1] + nums[i - 1];
    }

    for (int i = nums.size() - 2; i >= 0; --i)
    {
        rsum[i] = rsum[i + 1] + nums[i + 1];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (lsum[i] == rsum[i])
            return i;
    }
    return -1;
}

int bruteForce(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int lsum = 0, rsum = 0;
    }
}

int pivotIndex(vector<int> &nums)
{
    // return bruteForce(nums);
    return binarySearchApproach(nums);
}

int main()
{

    return 0;
}