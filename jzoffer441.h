#include <vector>
#include <string>

using namespace std;

int findNthDigit(int n)
{
    if (n < 10)
    {
        return n;
    }
    n = n - 10;

    unsigned long minNum = 10;
    unsigned long low = 0;
    unsigned long numsCount = 90;
    unsigned long digitsCount = 2;
    unsigned long high = numsCount * digitsCount - 1;

    while (n > high)
    {
        n -= (high + 1);
        ++digitsCount;
        numsCount *= 10;
        high = numsCount * digitsCount - 1;
        minNum *= 10;
    }

    unsigned long a = (n - low + 1) / digitsCount;
    unsigned long b = (n - low + 1) % digitsCount;

    if (b == 0)
    {
        a = minNum + a - 1;
        return (int)(a % 10);
    }
    else
    {
        a = minNum + a;
        unsigned long res = 0;
        while (b > 0)
        {
            res = a / minNum;
            b--;
            a -= res * minNum;
            minNum /= 10;
        }
        return (int)res;
    }
}