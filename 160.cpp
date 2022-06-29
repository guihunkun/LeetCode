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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode * pa=headA;
        ListNode * pb=headB;
        while(pa!=NULL)
        {
            while(pb!=NULL)
            {
                if(pa==pb)
                    return pa;
                pb=pb->next;
            }
            pa=pa->next;
            pb=headB;
        }
        return NULL;
    }
};

*/
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode * pa=headA;
        ListNode * pb=headB;
        int count=0;
        while(pa && pb)
        {
            if(count>2)
                break;
            if(pa==pb)
                return pa;
            if(pa->next==NULL || pb->next==NULL) 
                count++;
            pa=(pa->next==NULL)?pa=headB:pa->next;
            pb=(pb->next==NULL)?pb=headA:pb->next;
        }
        return NULL;
    }
};



class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==NULL || headB==NULL)
            return NULL;
        unordered_set<ListNode*> record;
        while(headA || headB)
        {
            if(headA)
            {
                if(record.find(headA)==record.end())
                {
                    record.insert(headA);
                    headA=headA->next;
                }
                else
                    return headA;
            }
            if(headB)
            {
                if(record.find(headB)==record.end())
                {
                    record.insert(headB);
                    headB=headB->next;
                }
                else
                    return headB;
            }
        }
        return NULL;
    }
};
