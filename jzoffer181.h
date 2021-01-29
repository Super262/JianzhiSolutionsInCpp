#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteNode(ListNode *head, int val)
{
    if (!head)
    {
        return nullptr;
    }
    if (head->val == val)
    {
        head = head->next;
    }

    ListNode *prev = nullptr;
    ListNode *current = head;
    while (current)
    {
        if (current->val == val)
        {
            prev->next = current->next;
            current = prev->next;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    return head;
}