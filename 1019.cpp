/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #if 0
class Solution 
{
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int> res;
        ListNode* cur = head;
        while(cur != NULL)
        {
            ListNode* next = cur->next;
            while(next != NULL)
            {
                if(next->val > cur->val) {
                    res.push_back(next->val);
                    break;
                }
                next = next->next;
            }  
            if(next == nullptr)
                res.push_back(0);
            cur = cur->next;
        }
        return res;
    }
};
#endif


class Solution 
{
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        stack<int> nodes;
        stack<int> stk;
        int length = 0;
        while(head) 
        {
            nodes.push(head->val);
            head = head->next;
            length++;
        }
        vector<int> result(length);
        while(!nodes.empty()) 
        {
            int node = nodes.top();
            nodes.pop();
            while(!stk.empty() && node >= stk.top()) {
                stk.pop();
            }
            result[--length] = stk.empty() ? 0 : stk.top();
            stk.push(node);
        }
        return result;
    }
};
