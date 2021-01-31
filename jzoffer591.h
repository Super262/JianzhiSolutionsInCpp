#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    queue<int> q;
    vector<int> result;
    for (int i = 0; i < k; ++i)
    {
        while (!q.empty() && q.front() < nums[i])
        {
            q.pop();
        }
        q.emplace(nums[i]);
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
            while (!q.empty())
            {
                q.pop();
            }
            for (int j = i - k + 1; j < i; ++j)
            {
                while (!q.empty() && q.front() < nums[j])
                {
                    q.pop();
                }
                q.emplace(nums[j]);
            }
        }
        while (!q.empty() && q.front() < nums[i])
        {
            q.pop();
        }
        q.emplace(nums[i]);
        result.emplace_back(q.front());
    }
    return result;
}