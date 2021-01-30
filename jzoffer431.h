#include <vector>

using namespace std;

int countDigitOne(int n)
{
    unsigned int result = 0;
    unsigned int low = 0;
    unsigned int cur = n % 10;
    unsigned int high = n / 10;
    unsigned int digit = 1;
    while (low != n)
    {
        if (cur == 0)
        {
            result += high * digit;
        }
        else if (cur == 1)
        {
            result += high * digit + low + 1;
        }
        else
        {
            result += (high + 1) * digit;
        }
        low += cur * digit;
        cur = high % 10;
        high /= 10;
        digit *= 10;
    }

    return (int)result;
}