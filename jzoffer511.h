#include <vector>
#include <algorithm>

using namespace std;

int mergeSort(vector<int> &nums, const int start, const int end, vector<int> &dest)
{
    if (start >= end - 1)
    {
        return 0;
    }
    const int mid = (end - start) / 2 + start; // This can avoid overflow!
    int pairsCount = 0;
    pairsCount += mergeSort(nums, start, mid, dest);
    pairsCount += mergeSort(nums, mid, end, dest);
    int i = start;
    int j = mid;
    int k = start;
    while (i < mid && j < end)
    {
        if (nums[i] > nums[j])
        {
            dest[k++] = nums[j++];
        }
        else
        {
            // We do this operation at this point because
            // we can only change the count of pairs when the left element of the pair exists!
            pairsCount += j - mid;

            dest[k++] = nums[i++];
        }
    }
    while (i < mid)
    {
        pairsCount += end - mid;
        dest[k++] = nums[i++];
    }
    while (j < end)
    {
        dest[k++] = nums[j++];
    }
    copy(dest.begin() + start, dest.begin() + end, nums.begin() + start);
    return pairsCount;
}

int reversePairs(vector<int> &nums)
{
    const int numsLen = nums.size();
    if (numsLen < 2)
    {
        return 0;
    }
    vector<int> temp(numsLen, 0);
    return mergeSort(nums, 0, numsLen, temp);
}