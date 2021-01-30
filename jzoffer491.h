#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int nthUglyNumber(int n)
{
    const int factorsCount = 3;
    vector<int> uglyNums = {1};
    vector<int> factors = {2, 3, 5};
    vector<int> factorPointers(3, 0);
    vector<int> tempValues(3, 0);
    int minV;
    while (uglyNums.size() < n)
    {
        minV = INT_MAX;
        for (int i = 0; i < factorsCount; ++i)
        {
            tempValues[i] = factors[i] * uglyNums[factorPointers[i]];
            minV = tempValues[i] < minV ? tempValues[i] : minV;
        }
        uglyNums.emplace_back(minV);
        for (int i = 0; i < factorsCount; ++i)
        {
            factorPointers[i] += tempValues[i] == minV ? 1 : 0;
        }
    }
    return uglyNums.back();
}