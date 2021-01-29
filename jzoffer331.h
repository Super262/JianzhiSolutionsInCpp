#include <vector>

using namespace std;

bool isValidBST(const vector<int> &postorder, const int start, const int end)
{
    if (start >= end)
    {
        return true;
    }

    int rightStart = start;
    while (rightStart < end && postorder[rightStart] < postorder[end])
    {
        ++rightStart;
    }
    for (int i = rightStart; i < end; ++i)
    {
        if (postorder[i] <= postorder[end])
        {
            return false;
        }
    }
    return isValidBST(postorder, start, rightStart - 1) && isValidBST(postorder, rightStart, end - 1);
}

bool verifyPostorder(vector<int> &postorder)
{
    return isValidBST(postorder, 0, postorder.size() - 1);
}