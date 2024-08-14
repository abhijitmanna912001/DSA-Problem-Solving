#include <iostream>
#include <vector>
using namespace std;

void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> temp(m + n); // Temporary array to hold the merged result
    int i = 0, j = 0, k = 0;

    // Merge the two arrays into temp
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            temp[k++] = nums1[i++];
        }
        else
        {
            temp[k++] = nums2[j++];
        }
    }

    // Copy any remaining elements from nums1
    while (i < m)
    {
        temp[k++] = nums1[i++];
    }

    // Copy any remaining elements from nums2
    while (j < n)
    {
        temp[k++] = nums2[j++];
    }

    // Copy the merged result back into nums1
    for (int p = 0; p < m + n; ++p)
    {
        nums1[p] = temp[p];
    }
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int total_len = n + m;
    int gap = total_len / 2 + total_len % 2;
    while (gap > 0)
    {
        int i = 0, j = gap;
        while (j < total_len)
        {
            if (j < n && nums1[i] > nums2[j])
                swap(nums1[i], nums1[j]);
            else if (j >= n && i < n && nums1[i] > nums2[j - n])
                swap(nums1[i], nums2[j - n]);
            else if (j >= n && i >= n && nums2[i - n] > nums2[j - n])
                swap(nums2[i - n], nums2[j - n]);
            j++;
            i++;
        }
        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
    }
}

int main()
{

    return 0;
}