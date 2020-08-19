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
    int numComponents(ListNode* head, vector<int>& G) 
    {
        unordered_set<int> rec(G.begin(), G.end());
        if(head==nullptr || G.size() < 1) 
            return 0;
        int num = 0, len = 0;
        while(head)
        {
            if(rec.find(head->val) != rec.end()) 
                ++len;//调用find函数。直接找。速度快。
            else
            {
                if(len != 0) 
                    ++num;
                len=0;
            }
            head = head->next;
        }
        return len > 0 ? num+1 : num;
    }
};
