#include <vector>

using namespace std;

int count(vector<int> &nums, const int start, const int end, const int target)
{
    if (start >= end)
    {
        return 0;
    }
    const int mid = start + (end - start) / 2;
    int result = 0;
    if (nums[mid] == target)
    {
        for (int i = mid; i >= 0; --i)
        {
            result += nums[i] == target ? 1 : 0;
        }
        for (int i = mid + 1; i < end; ++i)
        {
            result += nums[i] == target ? 1 : 0;
        }
    }
    else if (nums[mid] > target)
    {
        return count(nums, start, mid, target);
    }
    else
    {
        return count(nums, mid + 1, end, target);
    }
    return result;
}

int search(vector<int> &nums, int target)
{
    return count(nums, 0, nums.size(), target);
}