#include <vector>
#include <string>
#include <set>

using namespace std;

void swapCh(string &str, const int a, const int b)
{
    char ch = str[a];
    str[a] = str[b];
    str[b] = ch;
}

void getPermutation(string &str, const int start, const int end, vector<string> &result)
{
    if (start == end)
    {
        string temp = "";
        temp.push_back(str[start]);
        result.emplace_back(temp);
    }
    else
    {
        set<char> s;
        for (int i = start; i <= end; ++i)
        {
            if (s.find(str[i]) == s.end())
            {
                s.insert(str[i]);
                swapCh(str, i, start);
                vector<string> temp;
                getPermutation(str, start + 1, end, temp);
                swapCh(str, i, start);
                for (int j = 0; j < temp.size(); ++j)
                {
                    temp[j].insert(temp[j].begin(), str[i]);
                    result.emplace_back(temp[j]);
                }
            }
        }
    }
}

vector<string> permutation(string s)
{
    vector<string> result;
    getPermutation(s, 0, s.size() - 1, result);
    return result;
}
