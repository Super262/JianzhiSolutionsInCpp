#include <vector>
#include <string>
#include <map>

using namespace std;

char firstUniqChar(string s)
{
    const int sLen = s.size();
    char result = ' ';
    if (sLen == 0)
    {
        return result;
    }
    map<char, int> chToIndex;
    for (int i = 0; i < sLen; ++i)
    {
        if (chToIndex.find(s[i]) == chToIndex.end())
        {
            chToIndex[s[i]] = i;
        }
        else
        {
            chToIndex[s[i]] = sLen;
        }
    }
    int minI = sLen;
    for (map<char, int>::iterator iter = chToIndex.begin(); iter != chToIndex.end(); ++iter)
    {
        if (iter->second < minI)
        {
            minI = iter->second;
            result = iter->first;
        }
    }
    return result;
}