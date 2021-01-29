#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() == 0)
    {
        return nullptr;
    }
    TreeNode *root = createTree(preorder, 0, preorder.size(), inorder, 0, inorder.size() - 1);
    return root;
}

TreeNode *createTree(vector<int> &preorder, const int rootIndexInPre, const int preSize, vector<int> &inorder, const int startOfIn, const int endOfIn)
{
    if (rootIndexInPre >= preSize)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[rootIndexInPre]);
    int rootIndexOfIn = startOfIn;
    while (rootIndexOfIn <= endOfIn && inorder[rootIndexOfIn] != root->val)
    {
        ++rootIndexOfIn;
    }
    const int lChildSize = rootIndexOfIn - startOfIn;
    const int rChildSize = endOfIn - rootIndexOfIn;
    if (lChildSize)
    {
        root->left = createTree(preorder, rootIndexInPre + 1, preSize, inorder, startOfIn, rootIndexOfIn - 1);
    }
    if (rChildSize)
    {
        root->right = createTree(preorder, rootIndexInPre + lChildSize + 1, preSize, inorder, rootIndexOfIn + 1, endOfIn);
    }

    return root;
}