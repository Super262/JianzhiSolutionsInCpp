double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1.0;
    }
    bool isNegExp = false;
    double result = 1.0;
    unsigned int N;
    if (n < 0)
    {
        N = (unsigned int)(-(long)n);
        isNegExp = true;
    }
    else
    {
        N = (unsigned int)n;
    }

    while (N > 0)
    {
        if (N & 1)
        {
            result *= x;
        }
        N >>= 1;
        x *= x;
    }

    if (isNegExp)
    {
        result = 1.0 / result;
    }

    return result;
}