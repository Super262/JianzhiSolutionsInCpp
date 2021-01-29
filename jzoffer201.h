#include <vector>
#include <string>

using namespace std;

// The base must exist before 'e/E'.
// ".1" and "3." are valid bases.
// "." is not a valid base.
// The exponent could be 0.
// We have to ignore spaces before the number and after the number.
// If spaces occur, no characters other than spaces are allowed to exist!

bool isNumber(string s)
{
    const int sLen = s.size();
    int i = 0;

    // Ignore spaces
    while (i < sLen && s[i] == ' ')
    {
        ++i;
    }
    if (i >= sLen)
    {
        return false;
    }

    // Test the negative property and the positive property.
    if (s[i] == '+' || s[i] == '-')
    {
        ++i;
    }
    if (i >= sLen)
    {
        return false;
    }

    // Test the base.
    bool pointOccured = false;
    bool hasBase = false;

    bool needTestExpo = false;
    bool encounteredSpaces = false;
    char temp1;
    char temp2;
    while (i < sLen)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            hasBase = true;
            ++i;
        }
        else if (s[i] == '.')
        {
            if (pointOccured)
            {
                return false;
            }
            else
            {
                pointOccured = true;
                temp1 = i > 0 ? s[i - 1] : '\0';
                temp2 = i < sLen - 1 ? s[i + 1] : '\0';
                if ((temp1 > '9' || temp1 < '0') && (temp2 > '9' || temp2 < '0'))
                {
                    return false;
                }
                ++i;
            }
        }
        else if (s[i] == 'e' || s[i] == 'E')
        {
            needTestExpo = true;
            break;
        }
        else if (s[i] == ' ')
        {
            encounteredSpaces = true;
            ++i;
            break;
        }
        else
        {
            return false;
        }
    }
    if (!hasBase)
    {
        return false;
    }
    if (encounteredSpaces)
    {
        // Ignore spaces
        while (i < sLen)
        {
            if (s[i] != ' ')
            {
                return false;
            }
            ++i;
        }
    }
    if (i >= sLen && !needTestExpo)
    {
        return true;
    }

    // Test the exponent.
    bool hasExpo = false;
    ++i;
    if (i >= sLen)
    {
        return false;
    }
    if (s[i] == '+' || s[i] == '-')
    {
        ++i;
    }
    if (i >= sLen)
    {
        return false;
    }
    while (i < sLen)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            hasExpo = true;
            ++i;
        }
        else if (s[i] == ' ')
        {
            break;
        }
        else
        {
            return false;
        }
    }
    if (!hasExpo)
    {
        return false;
    }
    while (i < sLen)
    {
        // Ignore spaces
        if (s[i] != ' ')
        {
            return false;
        }
        ++i;
    }

    return true;
}