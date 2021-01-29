#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1 && !l2)
    {
        return nullptr;
    }
    if (!l1)
    {
        return l2;
    }
    if (!l2)
    {
        return l1;
    }
    ListNode *head = nullptr;
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    if (p1 && p2)
    {
        if (p1->val < p2->val)
        {
            head = new ListNode(p1->val);
            p1 = p1->next;
        }
        else
        {
            head = new ListNode(p2->val);
            p2 = p2->next;
        }
    }
    ListNode *current = head;
    while (p1 && p2)
    {
        if (p1->val < p2->val)
        {
            current->next = new ListNode(p1->val);
            p1 = p1->next;
        }
        else
        {
            current->next = new ListNode(p2->val);
            p2 = p2->next;
        }
        current = current->next;
    }
    while (p1)
    {
        current->next = new ListNode(p1->val);
        p1 = p1->next;
        current = current->next;
    }
    while (p2)
    {
        current->next = new ListNode(p2->val);
        p2 = p2->next;
        current = current->next;
    }
    return head;
}