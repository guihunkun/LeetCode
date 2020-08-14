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
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL)
        {
            return head;
        }
        ListNode* cur = head->next;
        head->next = NULL;
        ListNode* pre = head; 
        ListNode* ne = cur;
        while(cur != NULL)
        {
            ne = ne->next;
            cur->next = pre;
            pre = cur;
            cur = ne;
        }
        return pre;
    }
};
