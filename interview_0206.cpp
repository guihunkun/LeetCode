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
    bool isPalindrome(ListNode* head) 
    {
        vector<int> rec;
        while(head != NULL)
        {
            rec.push_back(head->val);
            head = head->next;
        }
        for(int i = 0; i < rec.size()/2; i++)
        {
            if(rec[i] != rec[rec.size()-i-1])
            {
                return false;
            }
        }
        return true;
    }
};
