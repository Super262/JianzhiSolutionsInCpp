#include <vector>
#include <string>

using namespace std;

string reverseWords(string s)
{
    string result;

    int offset = 0;
    bool noSpaces = true;
    const int strLen = s.size();
    for (int i = strLen - 1; i >= 0; --i)
    {
        if (s[i] == ' ')
        {
            if (!noSpaces)
            {
                result.push_back(' ');
                noSpaces = true;
                offset = result.length();
            }
        }
        else
        {
            noSpaces = false;
            result.insert(result.begin() + offset, s[i]);
        }
    }
    if (result.back() == ' ')
    {
        result.pop_back();
    }
    return result;
}