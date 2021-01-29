#include <vector>

using namespace std;

int cuttingRope(int n)
{
    if (n == 2)
    {
        return 1;
    }
    vector<int> dp(n + 1, 0);
    dp[2] = 1;

    int temp1;
    int temp2;
    for (int len = 3; len <= n; ++len)
    {
        for (int seg = 1; seg < len; ++seg)
        {
            temp1 = dp[seg] * (len - seg);
            temp2 = seg * (len - seg);
            temp1 = temp1 > temp2 ? temp1 : temp2;
            dp[len] = temp1 > dp[len] ? temp1 : dp[len];
        }
    }
    return dp[n];
}