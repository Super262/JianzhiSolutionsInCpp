#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void travelForK(TreeNode *root, const int k, vector<int> &output)
{
    if (root)
    {
        travelForK(root->right, k, output);
        if (output.size() == k)
        {
            return;
        }
        output.emplace_back(root->val);
        if (output.size() == k)
        {
            return;
        }
        travelForK(root->left, k, output);
    }
}

int kthLargest(TreeNode *root, int k)
{
    vector<int> temp;
    travelForK(root, k, temp);
    return temp.back();
}