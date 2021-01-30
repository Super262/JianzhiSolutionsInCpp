#include <vector>

using namespace std;

int partitionArray(vector<int> &arr, const int start, const int end)
{
    int pivot = arr[start];
    int pIndex = start;
    int i = start;
    int j = end;
    while (i < j)
    {
        while (j > i && arr[j] > pivot)
        {
            --j;
        }
        if (j > i)
        {
            arr[i] = arr[j];
        }
        while (i < j && arr[i] <= pivot)
        {
            ++i;
        }
        if (i < j)
        {
            arr[j] = arr[i];
        }
    }
    arr[i] = pivot;
    pIndex = i;
    return pIndex;
}

vector<int> getLeastNumbers(vector<int> &arr, int k)
{
    int start = 0;
    int end = arr.size() - 1;
    int tempK;
    while (start < end)
    {
        tempK = partitionArray(arr, start, end);
        if (tempK == k - 1)
        {
            break;
        }
        else if (tempK > k - 1)
        {
            end = tempK - 1;
        }
        else
        {
            start = tempK + 1;
        }
    }
    vector<int> result;
    for (int i = 0; i < k; ++i)
    {
        result.emplace_back(arr[i]);
    }
    return result;
}