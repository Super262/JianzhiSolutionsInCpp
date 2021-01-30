#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    const int numsLen = nums.size();
    vector<int> subSum(numsLen);
    subSum[0] = nums[0];
    int max = nums[0];

    int tempSum;
    for (int i = 1; i < numsLen; ++i)
    {
        tempSum = nums[i] + subSum[i - 1];
        subSum[i] = nums[i] > tempSum ? nums[i] : tempSum;
        if (subSum[i] > max)
        {
            max = subSum[i];
        }
    }
    return max;
}