#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int> &prices)
{
    const int numsLen = prices.size();
    int maxValue = 0;
    if (numsLen == 0)
    {
        return maxValue;
    }
    int preMin = prices[0];
    for (int i = 1; i < numsLen; ++i)
    {
        preMin = min(preMin, prices[i]);
        maxValue = max(prices[i] - preMin, maxValue);
    }
    return maxValue;
}