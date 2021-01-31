#include <vector>

using namespace std;

vector<int> constructArr(vector<int> &a)
{
    const int aLen = a.size();
    vector<int> result(aLen);
    vector<int> prevA(aLen, 1);
    vector<int> afterA(aLen, 1);
    for (int i = 1; i < aLen; ++i)
    {
        prevA[i] = a[i - 1] * prevA[i - 1];
    }
    for (int i = aLen - 2; i >= 0; --i)
    {
        afterA[i] = a[i + 1] * afterA[i + 1];
    }
    for (int i = 0; i < aLen; ++i)
    {
        result[i] = afterA[i] * prevA[i];
    }
    return result;
}