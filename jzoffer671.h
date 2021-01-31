#include <vector>
#include <string>

using namespace std;

int strToInt(string str)
{
    const int sLen = str.size();
    if (!sLen)
    {
        return 0;
    }

    // For spaces.
    int i = 0;
    while (i < sLen && str[i] == ' ')
    {
        ++i;
    }
    if (i >= sLen)
    {
        return 0;
    }

    // For the property.
    bool isNeg = false;
    if (str[i] == '-')
    {
        isNeg = true;
        ++i;
    }
    else if (str[i] == '+')
    {
        ++i;
    }
    else if (str[i] > '9' || str[i] < '0')
    {
        return 0;
    }

    //For digits.
    unsigned long long tempResult = 0;
    while (i < sLen)
    {
        if (str[i] <= '9' && str[i] >= '0')
        {
            tempResult *= 10;
            tempResult += (str[i] - '0');
            if (tempResult > INT_MAX && !isNeg)
            {
                return INT_MAX;
            }
            if (tempResult > ((unsigned long long)INT_MAX + 1) && isNeg)
            {
                return INT_MIN;
            }
            ++i;
        }
        else
        {
            break;
        }
    }

    // Done!
    // Define its property first, then convert it to "int", which can avoid overflow.
    int result = isNeg ? ((int)-tempResult) : ((int)tempResult);
    return result;
}