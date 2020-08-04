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
    // 快慢指针
    ListNode *detectCycle(ListNode *head) 
    {
        if(!head || !head->next)
        {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast&&fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                break;
            }
        }
        if(fast != slow)
        {
            return NULL;
        }
        fast = head;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
