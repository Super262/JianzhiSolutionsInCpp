#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *mirrorTree(TreeNode *root)
{
    if (!root)
    {
        return root;
    }
    TreeNode *l = root->left;
    TreeNode *r = root->right;
    root->left = mirrorTree(r);
    root->right = mirrorTree(l);
    return root;
}