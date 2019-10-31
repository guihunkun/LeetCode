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
private: 
    vector<int> nums;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) 
    {
        while(head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
        int n = rand()%(nums.size());
        return nums[n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */


