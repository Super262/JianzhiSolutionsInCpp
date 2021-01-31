#include <vector>
#include <algorithm>

using namespace std;

bool isStraight(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int zerosCount = 0;

    int i = 0;
    while (i < 5 && nums[i] == 0)
    {
        ++zerosCount;
        ++i;
    }

    ++i;
    while (i < 5)
    {
        if (nums[i] == nums[i - 1])
        {
            return false;
        }
        else
        {
            zerosCount -= nums[i] - nums[i - 1] - 1;
            ++i;
        }
    }

    return zerosCount >= 0;
}