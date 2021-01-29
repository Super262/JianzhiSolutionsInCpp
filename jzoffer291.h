#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    const int height = matrix.size();
    if (!height)
    {
        return vector<int>();
    }
    const int width = matrix[0].size();
    if (!width)
    {
        return vector<int>();
    }
    vector<int> result(height * width);
    int resultTop = -1;

    int xBottom = 0;
    int xTop = width - 1;
    int yBottom = 0;
    int yTop = height - 1;

    int x = 0;
    int y = 0;
    int direction = 1;
    while (x >= xBottom && x <= xTop && y >= yBottom && y <= yTop)
    {
        result[++resultTop] = matrix[y][x];
        switch (direction)
        {
        case 1:
        {
            if (x == xTop)
            {
                direction = 2;
                ++yBottom;
                ++y;
            }
            else
            {
                ++x;
            }
            break;
        }
        case 2:
        {
            if (y == yTop)
            {
                direction = 3;
                --xTop;
                --x;
            }
            else
            {
                ++y;
            }
            break;
        }
        case 3:
        {
            if (x == xBottom)
            {
                direction = 4;
                --yTop;
                --y;
            }
            else
            {
                --x;
            }
            break;
        }
        case 4:
        {
            if (y == yBottom)
            {
                direction = 1;
                ++xBottom;
                ++x;
            }
            else
            {
                --y;
            }
            break;
        }
        }
    }

    return result;
}