#include <vector>
#include <string>

using namespace std;

string reverseWords(string s)
{
    string result;

    int offset = 0;
    bool ignoreSpaces = true;
    const int strLen = s.size();
    for (int i = strLen - 1; i >= 0; --i)
    {
        if (s[i] == ' ')
        {
            if (!ignoreSpaces)
            {
                result.push_back(' ');
                ignoreSpaces = true;
                offset = result.length();
            }
        }
        else
        {
            ignoreSpaces = false;
            result.insert(result.begin() + offset, s[i]);
        }
    }
    if (result.back() == ' ')
    {
        result.pop_back();
    }
    return result;
}