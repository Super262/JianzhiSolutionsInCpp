#include <vector>
#include <queue>
#include <string>

using namespace std;

class MaxQueue
{
private:
    queue<int> data;
    deque<int> maximal;

public:
    MaxQueue()
    {
    }

    int max_value()
    {
        if (maximal.empty())
        {
            return -1;
        }
        else
        {
            return maximal.front();
        }
    }

    void push_back(int value)
    {
        while (!maximal.empty() && maximal.back() < value)
        {
            maximal.pop_back();
        }
        maximal.emplace_back(value);
        data.emplace(value);
    }

    int pop_front()
    {
        if (data.empty())
        {
            return -1;
        }
        else
        {
            int m = data.front();
            data.pop();
            if (m == maximal.front())
            {
                maximal.pop_front();
            }
            return m;
        }
    }
};