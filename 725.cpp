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
    vector<ListNode*> splitListToParts(ListNode* root, int k) 
    {
        vector<ListNode*> res(k, NULL);
        if(root == NULL)
        {
            return res;
        }
        ListNode* pos = root;
        int N = 0;
        while(pos != NULL)
        {
            N++;
            pos = pos->next;
        }
        int aLen = N/k;
        int rem = N%k;
        int i = 0;
        ListNode* head = root;
        ListNode* cur = NULL;
        while(i < k)
        {
            res[i] = head;
            int len = aLen + (rem > 0 ? 1 :0);
            for(int j = 0; j < len; j++)
            {
                cur = head;
                head = head->next;
            }
            cur->next = NULL;
            rem--;
            i++;
        }
        return res;
    }
};
