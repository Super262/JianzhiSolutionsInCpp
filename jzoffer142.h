int cuttingRope(int n)
{
    if (n == 2)
    {
        return 1;
    }
    if (n == 3)
    {
        return 2;
    }
    if (n == 4)
    {
        return 4;
    }

    unsigned long long result = 1;
    while (n > 4)
    {
        n -= 3;
        result *= 3;
        result %= 1000000007;
    }
    result *= n;
    result %= 1000000007;

    return (int)(result);
}