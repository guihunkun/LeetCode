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
    int kthToLast(ListNode* head, int k) 
    {
        ListNode* p;
        p = head;
        int i = 0;
        while(i < k && p != NULL)
        {
            p = p->next;
            i++;
        }
        if(i < k)
        {
            return -1;
        }
        ListNode* q = head;
        while(p != NULL)
        {
            p = p->next;
            q = q->next;
        }
        return q->val;
    }
};
