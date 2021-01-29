#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> reversePrint(ListNode *head)
{
    vector<int> result;
    ListNode *current = head;
    while (current)
    {
        result.insert(result.begin(), current->val);
        current = current->next;
    }
    return result;
}
