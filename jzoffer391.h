#include <vector>

using namespace std;

int majorityElement(vector<int> &nums)
{
    int result = nums[0];
    int votes = 0;
    for (int num : nums)
    {
        result = (votes == 0 ? num : result);
        votes += (result == num ? 1 : -1);
    }
    return result;
}