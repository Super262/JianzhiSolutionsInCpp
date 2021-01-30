#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
    {
        return nullptr;
    }
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    while (true)
    {
        if (p1 == p2)
        {
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
        if (!p1 && !p2)
        {
            return nullptr;
        }
        if (!p1)
        {
            p1 = headB;
        }
        if (!p2)
        {
            p2 = headA;
        }
    }
    return p1;
}