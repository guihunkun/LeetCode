/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* less = new ListNode(0);
        ListNode* great = new ListNode(0);
        ListNode* p1 = less,*p2 = great;
        ListNode* p = head;
        while(p != NULL)
        {
            if(p->val < x) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }
        if(great != NULL) {
            p1->next = great->next;
        }
        p2->next = nullptr;
        return less->next;
    }
};
