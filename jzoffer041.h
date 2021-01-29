#include <vector>

using namespace std;

bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
{
    const int height = matrix.size();
    if (height < 1)
    {
        return false;
    }
    const int width = matrix[0].size();
    if (width < 1)
    {
        return false;
    }

    int y = height - 1;
    int x = 0;
    int temp;
    while (y >= 0 && x < width)
    {
        temp = matrix[y][x];
        if (temp == target)
        {
            return true;
        }
        else if (temp > target)
        {
            --y;
        }
        else
        {
            ++x;
        }
    }

    return false;
}