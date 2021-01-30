#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(int &a, int &b)
{
    string sa = to_string(a);
    string sb = to_string(b);
    return (sa + sb) < (sb + sa);
}

string minNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), cmp);
    string s;
    for (int &num : nums)
    {
        s.append(to_string(num));
    }
    return s;
}