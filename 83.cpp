/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {

        
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
		ListNode* pre=head;
		ListNode* cur=head->next;
		while(cur!=NULL)
		{
			
			if(cur->val==pre->val)
			{
				pre->next=cur->next;//删除重复的节点
			}
			else 
            {
				pre=pre->next;
				
			}
			cur=cur->next;
		}
		return head;

    }
};
*/
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* cur=head;
        
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode* ne=head->next;
        while(ne!=NULL)
        {
            if(cur->val==ne->val)
                ne=ne->next;
            else
            {
            	cur->next=ne;
            	cur=ne;
            	ne=ne->next;
			}
        }
        cur->next=NULL;
        return head; 
    }
};