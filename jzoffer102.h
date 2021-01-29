int numWays(int n)
{
    int f0 = 1;
    int f1 = 1;
    if (n == 0)
    {
        return f0;
    }
    if (n == 1)
    {
        return f1;
    }
    int fn;
    for (int i = 2; i <= n; ++i)
    {
        fn = (f0 + f1) % 1000000007;
        f0 = f1;
        f1 = fn;
    }
    return fn;
}