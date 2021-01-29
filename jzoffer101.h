int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    const int bound = 1000000007;
    int f0 = 0, f1 = 1, fn;
    for (int i = 2; i <= n; ++i)
    {
        fn = (f0 + f1) % bound;
        f0 = f1;
        f1 = fn;
    }
    return fn;
}