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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* newhead = new ListNode(-1);
        newhead->next = head;
        ListNode* pre = newhead;
        ListNode* cur = head;
        while(cur != NULL)
        {
            if(cur->val == val)
            {
                cur = cur->next;
                pre->next = cur;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return newhead->next;
    }
};