using namespace std;

int translateNum(int num)
{
    if (num < 10)
    {
        return 1;
    }
    if (num < 100)
    {
        if (num > 25)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    int res = 0;

    res += translateNum(num / 10);

    int twoDigit = num % 100;
    if (twoDigit > 9 && twoDigit < 26)
    {
        res += translateNum(num / 100);
    }

    return res;
}