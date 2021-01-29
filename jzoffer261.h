#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSame(TreeNode *A, TreeNode *B)
{
    if (!B)
    {
        return true;
    }
    if (!A)
    {
        return false;
    }
    if (B->val != A->val)
    {
        return false;
    }
    return isSame(A->left, B->left) && isSame(A->right, B->right);
}

bool findEntryAndTest(TreeNode *A, TreeNode *B)
{
    if (A && B)
    {
        if (A->val == B->val && isSame(A, B))
        {
            return true;
        }
        else
        {
            return findEntryAndTest(A->left, B) || findEntryAndTest(A->right, B);
        }
    }
    else
    {
        return false;
    }
}

bool isSubStructure(TreeNode *A, TreeNode *B)
{
    return findEntryAndTest(A, B);
}
