#include <vector>

using namespace std;

vector<int> exchange(vector<int> &nums)
{
    int i = 0, j = nums.size() - 1;
    int temp;
    while (i < j)
    {
        while (nums[i] % 2 == 1 && i < j)
        {
            ++i;
        }
        while (nums[j] % 2 == 0 && j > i)
        {
            --j;
        }
        if (i < j)
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    return nums;
}