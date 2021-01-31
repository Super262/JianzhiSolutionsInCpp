#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    else
    {
        const int left = maxDepth(root->left);
        const int right = maxDepth(root->right);
        return left > right ? left + 1 : right + 1;
    }
}