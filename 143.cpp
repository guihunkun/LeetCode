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
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* cur=head;
        ListNode* nex1=head->next;
        head->next=NULL;
        while(nex1!=NULL)
        {
            ListNode* nex2=nex1->next;
            nex1->next=cur;
            cur=nex1;
            nex1=nex2;
        }
        return cur;
    }
    public:
    void reorderList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
            return;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        ListNode* l1=head;
        ListNode* l2=fast;
        ListNode* l3=reverse(l2);
        head=l1;
        ListNode* l1ne=l1->next;
        ListNode* l3ne=l3->next;
        while(l3!=NULL)
        {
            l1->next=l3;
            l3->next=l1ne;
            l1=l1ne;
            if(l1ne==NULL || l3ne==NULL)
                break;
            l1ne=l1ne->next;
            l3=l3ne;
            l3ne=l3ne->next;
        }
    }


};
