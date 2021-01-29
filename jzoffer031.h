#include <vector>

using namespace std;

int findRepeatNumber(std::vector<int> &nums)
{
    vector<bool> existed(nums.size(), false);
    for (int num : nums)
    {
        if (existed[num])
        {
            return num;
        }
        else
        {
            existed[num] = true;
        }
    }
    return -1;
}