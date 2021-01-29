#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *prev = nullptr;
    ListNode *current = head;
    ListNode *next = nullptr;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}