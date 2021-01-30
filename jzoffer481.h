#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int indexOf(string &s, char ch, const int start, const int end)
{
    for (int i = end; i >= start; --i)
    {
        if (s[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

int lengthOfLongestSubstring(string s)
{
    const int sLen = s.size();
    if (sLen < 2)
    {
        return sLen;
    }

    int result = 1;
    int i = 0;
    int j = 1;
    int indexInSub;
    int tempRes;
    while (i < j && j < sLen)
    {
        indexInSub = indexOf(s, s[j], i, j - 1);
        ++j;
        if (indexInSub != -1)
        {
            i = indexInSub + 1;
        }
        tempRes = j - i;
        result = tempRes > result ? tempRes : result;
    }

    return result;
}