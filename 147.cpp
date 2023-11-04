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
    ListNode* insertionSortList(ListNode* head) 
    {
        if(head==NULL||head->next==NULL) //bug1:特殊情况处理。
            return head;
        ListNode* cur=head;
        ListNode* next=head;
        ListNode* new_head=NULL;
        ListNode* new_tail=NULL;
        while(cur!=NULL)
        {
            next=cur->next;
            if(new_head==NULL){ //如果新链表的头结点为空
                new_head=cur;
                new_tail=cur;
                new_tail->next=NULL;
            }else{
                ListNode* tmp_pre=NULL;
                ListNode* tmp_cur=new_head;
                while(tmp_cur!=NULL&&cur->val>tmp_cur->val) { 
                        //bug2:注意不能少了判断语句tmp_cur!=NULL
                        tmp_pre=tmp_cur;
                        tmp_cur=tmp_cur->next;
                }
                if(tmp_pre==NULL){//假如旧元素放入新链表的表头
                    cur->next=new_head;
                    new_head=cur; 
                }else if(tmp_cur==NULL){ //就如旧元素放入新链表的表尾
                    new_tail->next=cur;
                    new_tail=cur;
                    new_tail->next=NULL; //bug3:不要忘了tail节点还要用NULL表示节点
                }else{//假如旧元素放入新链表的表中
                    cur->next=tmp_cur;
                    tmp_pre->next=cur;
                }
            }
            cur=next;
        }
        return new_head;
    }
};
/*
1 要记得把排序好的新链表和待排序的旧链表断开，也就是排序好的新链表的尾节点要赋值NULL。否则最后就乱了。
2 什么叫做插入排序，从A[1]到A[n]，依次把旧链表中的旧元素放入新链表的正确位置中，新链表是从没有元素开始逐渐排好序的，每加入一个旧元素，就把它放入正确的位置中。有三种可能的位置，新链表的表头，新链表的表中，新链表的表尾，因为在不同的位置会造成对head和tail指针做不同的处理，所以需要分情况讨论。
*/


