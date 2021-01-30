#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxValue(vector<vector<int>> &grid)
{
    const int height = grid.size();
    if (height == 0)
    {
        return 0;
    }
    const int width = grid[0].size();
    if (width == 0)
    {
        return 0;
    }

    vector<vector<int>> f(height, vector<int>(width, 0));
    f[0][0] = grid[0][0];

    for (int i = 1; i < width; ++i)
    {
        f[0][i] = f[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < height; ++i)
    {
        f[i][0] = f[i - 1][0] + grid[i][0];
    }

    int v1, v2;
    for (int i = 1; i < height; ++i)
    {
        for (int j = 1; j < width; ++j)
        {
            v1 = f[i - 1][j] + grid[i][j];
            v2 = f[i][j - 1] + grid[i][j];
            f[i][j] = v1 > v2 ? v1 : v2;
        }
    }

    return f[height - 1][width - 1];
}