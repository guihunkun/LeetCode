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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int num = 0;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(l1 != NULL || l2 != NULL || num != 0)
        {
            if(l1 != NULL)
            {
                num += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                num += l2->val;
                l2 = l2->next;
            }
            ListNode* node = new ListNode(num%10);
            num /= 10;
            cur->next = node;
            cur = cur->next;
        }
        return head->next;
    }
};
