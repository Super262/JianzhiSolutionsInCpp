#include <vector>
#include <string>

using namespace std;

vector<double> dicesProbability(int n)
{
    vector<double> result(5 * n + 1);

    vector<vector<int>> f(n + 1);

    int countOfEvents = 6;
    int maxSum = 6;
    int prevMax;

    f[1] = vector<int>(maxSum + 1, 1);
    for (int i = 2; i <= n; ++i)
    {
        countOfEvents *= 6;
        prevMax = maxSum;
        maxSum = i * 6;
        f[i] = vector<int>(maxSum + 1, 0);
        for (int j = i; j <= maxSum; ++j)
        {
            for (int k = 1; k <= 6; ++k)
            {
                if (k <= j - i + 1 && k >= j - prevMax)
                {
                    f[i][j] += f[1][k] * f[i - 1][j - k];
                }
            }
        }
    }

    for (int i = n; i <= maxSum; ++i)
    {
        result[i - n] = ((double)f[n][i]) / ((double)countOfEvents);
    }

    return result;
}