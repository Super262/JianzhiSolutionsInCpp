int add(int a, int b)
{
    unsigned long A = a;
    unsigned long B = b;
    unsigned long C;
    while (B)
    {
        C = ((A & B) << 1);
        A ^= B;
        B = C;
    }
    return (int)A;
}