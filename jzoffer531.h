#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    int result = 0;
    if (nums.size() == 0)
    {
        return result;
    }
    for (int num : nums)
    {
        result += num == target ? 1 : 0;
    }
    return result;
}