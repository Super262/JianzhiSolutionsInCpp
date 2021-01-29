#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool testRecursively(TreeNode *A, TreeNode *B)
{
    if (!A && !B)
    {
        return true;
    }
    if (!A || !B)
    {
        return false;
    }
    if (A->val != B->val)
    {
        return false;
    }
    return testRecursively(A->right, B->left) && testRecursively(A->left, B->right);
}

bool isSymmetric(TreeNode *root)
{
    if (!root)
    {
        return true;
    }
    return testRecursively(root->left, root->right);
}