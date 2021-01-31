#include <vector>

using namespace std;

// https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-by-lee/
int lastRemaining(int n, int m)
{
    int x = 0;
    for (int i = 2; i <= n; ++i)
    {
        x = (m + x) % i;
    }
    return x;
}