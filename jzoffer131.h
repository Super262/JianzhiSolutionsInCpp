#include <vector>
#include <string>

using namespace std;

int sumOfDigits(int num)
{
    if (num < 0)
    {
        num = -num;
    }
    int result = 0;
    while (num > 0)
    {
        result += num % 10;
        num /= 10;
    }
    return result;
}

int getCountByBFS(const int maxY, const int maxX, const int startY, const int startX, const int k, vector<vector<bool>> &visited)
{
    if (startY >= maxY || startX >= maxX || visited[startY][startX])
    {
        return 0;
    }
    int result = 0;
    if (sumOfDigits(startY) + sumOfDigits(startX) <= k)
    {
        result = getCountByBFS(maxY, maxX, startY + 1, startX, k, visited) + getCountByBFS(maxY, maxX, startY, startX + 1, k, visited) + 1;
        visited[startY][startX] = true;
    }
    return result;
}

int movingCount(int m, int n, int k)
{
    vector<vector<bool>> visited(m);
    for (int i = 0; i < m; ++i)
    {
        visited[i] = vector<bool>(n, false);
    }
    return getCountByBFS(m, n, 0, 0, k, visited);
}