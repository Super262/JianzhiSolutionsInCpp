#include <vector>
#include <stack>

using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    const int len = pushed.size();
    stack<int> s;

    int i = 0;
    int j = 0;
    while (i < len && j < len)
    {
        while (!s.empty() && j < len && popped[j] == s.top())
        {
            s.pop();
            ++j;
        }
        if (j < len && pushed[i] == popped[j])
        {
            ++j;
        }
        else
        {
            s.emplace(pushed[i]);
        }
        ++i;
    }
    while (!s.empty())
    {
        if (j == len || popped[j] != s.top())
        {
            return false;
        }
        else
        {
            s.pop();
            ++j;
        }
    }
    return s.empty() && j == len;
}