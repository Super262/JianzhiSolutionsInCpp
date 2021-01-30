#include <queue>

using namespace std;

class MedianFinder
{
private:
    // There must have spaces! Otherwise, it will be labeled as ">>"
    priority_queue<int, vector<int>, less<int>> smallerOnes;
    priority_queue<int, vector<int>, greater<int>> largerOnes;

public:
    /** initialize your data structure here. */

    MedianFinder() {}

    void addNum(int num)
    {
        if (smallerOnes.empty() && largerOnes.empty())
        {
            smallerOnes.emplace(num);
            return;
        }
        if (!largerOnes.empty() && num >= largerOnes.top())
        {
            largerOnes.emplace(num);
        }
        else
        {
            smallerOnes.emplace(num);
        }
        if (smallerOnes.size() > (largerOnes.size() + 1))
        {
            largerOnes.emplace(smallerOnes.top());
            smallerOnes.pop();
        }
        else if (largerOnes.size() > (smallerOnes.size() + 1))
        {
            smallerOnes.emplace(largerOnes.top());
            largerOnes.pop();
        }
    }

    double findMedian()
    {
        if (smallerOnes.empty() && largerOnes.empty())
        {
            return 0;
        }
        if (smallerOnes.size() == largerOnes.size())
        {
            return (double)(smallerOnes.top() + largerOnes.top()) / 2;
        }
        if (smallerOnes.size() - largerOnes.size() == 1)
        {
            return (double)smallerOnes.top();
        }
        else
        {
            return (double)largerOnes.top();
        }
    }
};