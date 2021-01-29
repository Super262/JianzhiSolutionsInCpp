#include <list>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

void createList(Node *root, list<Node *> &output)
{
    if (!root)
    {
        return;
    }
    createList(root->left, output);
    if (!output.empty())
    {
        output.back()->right = root;
        root->left = output.back();
    }
    output.emplace_back(root);
    createList(root->right, output);
}

Node *treeToDoublyList(Node *root)
{
    list<Node *> output;
    Node *head = nullptr;
    createList(root, output);
    if (!output.empty())
    {
        output.front()->left = output.back();
        output.back()->right = output.front();
        head = output.front();
    }
    return head;
}