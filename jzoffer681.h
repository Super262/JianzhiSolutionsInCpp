#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool getPath(TreeNode *root, TreeNode *target, vector<TreeNode *> &output)
{
    if (!root)
    {
        return false;
    }
    if (root->val == target->val)
    {
        output.emplace_back(root);
        return true;
    }
    else
    {
        if (getPath(root->left, target, output))
        {
            output.emplace_back(root);
            return true;
        }
        else if (getPath(root->right, target, output))
        {
            output.emplace_back(root);
            return true;
        }
        else
        {
            return false;
        }
    }
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || !p || !q)
    {
        return nullptr;
    }
    TreeNode *firstSame = nullptr;
    vector<TreeNode *> output1;
    vector<TreeNode *> output2;
    getPath(root, p, output1);
    getPath(root, q, output2);
    while (!output1.empty() && !output2.empty() && output1.back() == output2.back())
    {
        firstSame = output1.back();
        output1.pop_back();
        output2.pop_back();
    }
    return firstSame;
}