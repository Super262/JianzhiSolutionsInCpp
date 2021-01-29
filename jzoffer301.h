#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> data;
    stack<int> minimal;
    unsigned int size = 0;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        if (!size)
        {
            minimal.emplace(x);
        }
        else
        {
            if (x > minimal.top())
            {
                minimal.emplace(minimal.top());
            }
            else
            {
                minimal.emplace(x);
            }
        }
        data.emplace(x);
        ++size;
    }

    void pop()
    {
        if (size)
        {
            data.pop();
            minimal.pop();
            --size;
        }
    }

    int top()
    {
        if (!size)
        {
            return -1;
        }
        return data.top();
    }

    int min()
    {
        if (!size)
        {
            return -1;
        }
        return minimal.top();
    }
};