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
    ListNode* getKthFromEnd(ListNode* head, int k) 
    {
        ListNode* fast = head;
        int i = 1;
        while(fast != NULL && i <= k)
        {
            fast = fast->next;
            i++;
        }
        ListNode* slow = head;
        while(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
