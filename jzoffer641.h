int quickMulti(int a, int b)
{
    int result = 0;
    while (b)
    {
        if (b & 1)
        {
            result += a;
        }
        b >>= 1;
        a <<= 1;
    }
    return result;
}

int sumNums(int n)
{
    return (quickMulti(n, n + 1) >> 1);
}