#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    if (nums.size() < 2)
    {
        return vector<int>();
    }
    int i = 0, j = nums.size() - 1;
    vector<int> result = {nums[i], nums[j]};

    int tempSum;
    while (i < j)
    {
        tempSum = nums[i] + nums[j];
        if (tempSum == target)
        {
            result[0] = nums[i];
            result[1] = nums[j];
            return result;
        }
        else if (tempSum > target)
        {
            --j;
        }
        else
        {
            ++i;
        }
    }

    return result;
}