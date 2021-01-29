#include <string>

using namespace std;

string replaceSpace(string s)
{
    string res;
    for (char c : s)
    {
        if (c == ' ')
        {
            res.append("%20");
        }
        else
        {
            res.push_back(c);
        }
    }
    return res;
}
