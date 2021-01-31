#include <vector>

using namespace std;

int singleNumber(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    vector<int> count(32, 0);
    for (int num : nums)
    {
        for (int i = 0; i < 32; ++i)
        {
            count[i] += (num & 1);
            num >>= 1;
        }
    }
    int result = 0;
    unsigned int base = 1; // We use "unsigned type" to avoid overflow.

    for (int i = 0; i < 32; ++i)
    {
        count[i] = count[i] % 3;
        result += base * count[i];
        base *= 2;
    }
    return result;
}