#include <vector>

using namespace std;

vector<vector<int>> findContinuousSequence(int target)
{
    vector<vector<int>> result;
    vector<int> tempVec;
    int l = 1;
    int r = 2;
    int tempSum;
    while (l < r)
    {
        tempSum = (l + r) * (r - l + 1) / 2;
        if (tempSum == target)
        {
            tempVec.clear();
            for (int i = l; i <= r; ++i)
            {
                tempVec.emplace_back(i);
            }
            result.emplace_back(tempVec);
            ++l;
        }
        else if (tempSum > target)
        {
            ++l;
        }
        else
        {
            ++r;
        }
    }
    return result;
}