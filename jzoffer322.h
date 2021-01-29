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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (!root)
    {
        return result;
    }
    queue<TreeNode *> q;
    TreeNode *prevNode = nullptr;
    int prevSize = 1;
    int currentSize = 0;
    q.emplace(root);
    while (!q.empty())
    {
        result.emplace_back(vector<int>());
        while (prevSize)
        {
            --prevSize;
            prevNode = q.front();
            q.pop();
            result.back().emplace_back(prevNode->val);
            if (prevNode->left)
            {
                q.emplace(prevNode->left);
                ++currentSize;
            }
            if (prevNode->right)
            {
                q.emplace(prevNode->right);
                ++currentSize;
            }
        }
        prevSize = currentSize;
        currentSize = 0;
    }
    return result;
}