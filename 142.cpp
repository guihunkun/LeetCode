/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
            return NULL;
        ListNode * fast = head, * slow = head;
        bool isCycle = false;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
            {
                isCycle = true;
                break;
            }
        }
        if(! isCycle)
            return NULL;
        fast = head;
        while(slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
