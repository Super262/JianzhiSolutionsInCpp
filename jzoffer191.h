#include <vector>
#include <string>

using namespace std;

bool matchesAtTail(const int sLen, const int pLen, string &s, string &p)
{
    // Now we assume that the length of p is greater than 0.

    if (sLen == 0)
    {
        return false;
    }
    if (p[pLen - 1] == '.')
    {
        return true;
    }
    return p[pLen - 1] == s[sLen - 1];
}

bool isMatch(string s, string p)
{
    const int sLen = s.size();
    const int pLen = p.size();

    vector<vector<bool>> f(sLen + 1, vector<bool>(pLen + 1, false));
    f[0][0] = true;

    for (int i = 0; i <= sLen; ++i)
    {
        for (int j = 1; j <= pLen; ++j)
        {
            if (p[j - 1] == '*')
            {
                if (matchesAtTail(i, j - 1, s, p))
                {
                    f[i][j] = f[i - 1][j] || f[i][j - 2];
                }
                else
                {
                    f[i][j] = f[i][j - 2];
                }
            }
            else
            {
                if (matchesAtTail(i, j, s, p))
                {
                    f[i][j] = f[i - 1][j - 1];
                }
                else
                {
                    f[i][j] = false;
                }
            }
        }
    }
    return f[sLen][pLen];
}