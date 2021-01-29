#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> pathSum(TreeNode *root, int sum)
{
    if (root)
    {
        if (root->val == sum && !root->left && !root->right)
        {
            return vector<vector<int>>(1, vector<int>(1, root->val));
        }
        else
        {
            vector<vector<int>> left = pathSum(root->left, sum - root->val);
            vector<vector<int>> right = pathSum(root->right, sum - root->val);
            for (vector<int> &p : right)
            {
                left.emplace_back(p);
            }
            for (vector<int> &p : left)
            {
                p.emplace(p.begin(), root->val);
            }
            return left;
        }
    }
    return vector<vector<int>>();
}