#include <vector>

using namespace std;

vector<int> singleNumbers(vector<int> &nums)
{
    if (nums.size() < 2)
    {
        return vector<int>();
    }
    int tempResult = 0;
    for (int num : nums)
    {
        tempResult ^= num;
    }
    int div = 1;
    while ((div & tempResult) == 0)
    {
        div <<= 1;
    }
    vector<int> result(2, 0);
    for (int num : nums)
    {
        if ((div & num) == 0)
        {
            result[0] ^= num;
        }
        else
        {
            result[1] ^= num;
        }
    }
    return result;
}