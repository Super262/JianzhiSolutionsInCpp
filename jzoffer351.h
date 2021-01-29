#include <vector>
#include <map>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (!head)
    {
        return nullptr;
    }
    map<Node *, Node *> oldToNew;
    Node *oldCur = head;
    while (oldCur)
    {
        Node *newCur = new Node(oldCur->val);
        oldToNew[oldCur] = newCur;
        oldCur = oldCur->next;
    }
    for (map<Node *, Node *>::iterator iter = oldToNew.begin(); iter != oldToNew.end(); ++iter)
    {
        if (iter->first->next)
        {
            iter->second->next = oldToNew[iter->first->next];
        }
        if (iter->first->random)
        {
            iter->second->random = oldToNew[iter->first->random];
        }
    }
    return oldToNew[head];
}