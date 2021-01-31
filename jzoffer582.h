#include <vector>
#include <string>

using namespace std;

string reverseLeftWords(string s, int n)
{
    string result;
    const int sLen = s.size();

    for (int i = n; i < sLen; ++i)
    {
        result.push_back(s[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        result.push_back(s[i]);
    }

    return result;
}