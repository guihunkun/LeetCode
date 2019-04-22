#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/// LinkedList 测试辅助函数

// 根据n个元素的数组arr创建一个链表, 并返回链表的头
ListNode* createLinkedList(int arr[], int n){

    if(n == 0)
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for(int i = 1 ; i < n ; i ++){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

// 打印以head为头结点的链表信息内容
void printLinkedList(ListNode* head){

    ListNode* curNode = head;
    while(curNode != NULL){
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }

    cout << "NULL" << endl;

    return;
}

// 释放以head为头结点的链表空间
void deleteLinkedList(ListNode* head){

    ListNode* curNode = head;
    while(curNode != NULL){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }

    return;
}


// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/description/
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head)
	{

        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != NULL){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* newhead = new ListNode(-1);
        newhead->next = head;
        ListNode* pre = newhead;
        ListNode* cur = head;
        while(cur != NULL)
        {
            if(cur->val == val)
            {
                cur = cur->next;
                pre->next = cur;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return newhead->next;
    }
    ListNode* greversr(ListNode* head)
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
        printLinkedList(l1);
        cout<<endl;
        printLinkedList(l2);
        cout<<endl;
        ListNode* l3=greversr(l2);
        printLinkedList(l3);
        return;
    }

};

int main(){

    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);

    ListNode* head = createLinkedList(arr, n);
    printLinkedList(head);

    Solution().reorderList(head);
    //ListNode* head2 = Solution().removeElements(head,3);
   // printLinkedList(head2);

    //deleteLinkedList(head2);

    return 0;
}