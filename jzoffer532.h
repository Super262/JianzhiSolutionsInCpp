#include <vector>

using namespace std;

int missingNumber(vector<int> &nums)
{
    const int numsLen = nums.size();
    for (int i = 0; i < numsLen; ++i)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }
    return -1;
}