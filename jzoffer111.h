#include <vector>

using namespace std;

int minArray(vector<int> &numbers)
{
    const int len = numbers.size();
    if (len == 1)
    {
        return numbers[0];
    }
    int i = 1;
    while (i < len && numbers[i] >= numbers[i - 1])
    {
        ++i;
    }
    if (i == len)
    {
        return numbers[0];
    }
    else
    {
        return numbers[i];
    }
}