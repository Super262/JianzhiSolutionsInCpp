#include <stack>

using namespace std;

class CQueue
{
private:
    stack<int> sForAdd;
    stack<int> sForPoll;
    int size;
    int first;

public:
    CQueue()
    {
        size = 0;
        first = -1;
    }

    void appendTail(int value)
    {
        ++size;
        sForAdd.emplace(value);
    }

    int deleteHead()
    {
        if (size == 0)
        {
            return -1;
        }
        else
        {
            if (sForPoll.empty())
            {
                while (!sForAdd.empty())
                {
                    sForPoll.emplace(sForAdd.top());
                    sForAdd.pop();
                }
            }
            first = sForPoll.top();
            sForPoll.pop();
            --size;
            return first;
        }
    }
};