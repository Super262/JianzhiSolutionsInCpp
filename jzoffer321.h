#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> levelOrder(TreeNode *root)
{
    vector<int> result;
    if (!root)
    {
        return result;
    }
    queue<TreeNode *> q;
    q.emplace(root);

    TreeNode *current = nullptr;
    while (!q.empty())
    {
        current = q.front();
        q.pop();
        result.emplace_back(current->val);
        if (current->left)
        {
            q.emplace(current->left);
        }
        if (current->right)
        {
            q.emplace(current->right);
        }
    }
    return result;
}