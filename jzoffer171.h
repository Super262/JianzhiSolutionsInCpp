#include <vector>
#include <cmath>

using namespace std;

vector<int> printNumbers(int n)
{
    const int bound = pow(10, n) - 1;
    vector<int> result(bound);
    for (int i = 0; i < bound; ++i)
    {
        result[i] = i + 1;
    }
    return result;
}