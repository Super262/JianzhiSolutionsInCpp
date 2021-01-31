#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> q;
    vector<int> result;
    for (int i = 0; i < k; ++i)
    {
        while (!q.empty() && q.back() < nums[i])
        {
            q.pop_back();
        }
        q.emplace_back(nums[i]);
    }
    if (!q.empty())
    {
        result.emplace_back(q.front());
    }
    const int numsLen = nums.size();

    int removedNum;
    for (int i = k; i < numsLen; ++i)
    {
        removedNum = nums[i - k];
        if (!q.empty() && removedNum == q.front())
        {
            q.pop_front();
        }
        while (!q.empty() && q.back() < nums[i])
        {
            q.pop_back();
        }
        q.emplace_back(nums[i]);
        result.emplace_back(q.front());
    }
    return result;
}