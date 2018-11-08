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

/// LinkedList ���Ը�������

// ����n��Ԫ�ص�����arr����һ������, �����������ͷ
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

// ��ӡ��headΪͷ����������Ϣ����
void printLinkedList(ListNode* head){

    ListNode* curNode = head;
    while(curNode != NULL){
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }

    cout << "NULL" << endl;

    return;
}

// �ͷ���headΪͷ��������ռ�
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
// ʱ�临�Ӷ�: O(n)
// �ռ临�Ӷ�: O(1)
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

};

int main(){

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    ListNode* head = createLinkedList(arr, n);
    printLinkedList(head);

    ListNode* head2 = Solution().removeElements(head,3); 
    printLinkedList(head2);

    deleteLinkedList(head2);

    return 0;
}
