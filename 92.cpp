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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
         ListNode dumb(0);
         dumb.next = head;
         if(m == n) 
             return head;
         ListNode* preM = &dumb;//保存m之前结点
         ListNode* pM = head,*pN = head ,*temp = head;
         int index=1;
         while(pN != NULL)
         {
             if(index < m)
             {
                 index++;
                 preM = pM;
                 pM = pM->next;
                 pN = pN->next;
             }
             else if(index >= m && index <= n)
             {
                 temp = pN->next;
                 pN->next = preM->next;
                 preM->next =pN;
                 pN = temp;
                 index++;
             }
             else if(index > n)        
                 break;
         }
         pM->next = pN;
         return dumb.next;
    }
    
};
