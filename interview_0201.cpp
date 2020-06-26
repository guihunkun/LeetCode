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
    ListNode* removeDuplicateNodes(ListNode* head) 
    {
        if(head == nullptr)
            return head;
        unordered_set<int> occurred = {head->val};
        ListNode* pos = head;
        while(pos->next != nullptr)
        {
            ListNode* cur = pos->next;
            if(!occurred.count(cur->val))
            {
                occurred.insert(cur->val);
                pos = pos->next;
            }
            else
            {
                pos->next = pos->next->next;
            }
        }
        pos->next = nullptr;
        return head;
    }
};
