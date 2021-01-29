#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getKthFromEnd(ListNode *head, int k)
{
    ListNode *kNode = nullptr;
    ListNode *current = head;
    while (current && k > 1)
    {
        current = current->next;
        --k;
    }
    if (current)
    {
        kNode = head;
        while (current->next)
        {
            current = current->next;
            kNode = kNode->next;
        }
    }

    return kNode;
}