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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        		stack<int> stackL1;
		stack<int> stackL2;
		while(l1){
			stackL1.push(l1->val);
			l1=l1->next;
		}
		while(l2){
			stackL2.push(l2->val);
			l2=l2->next;
		}
 
		ListNode* head=NULL;
		int sum=0;
 
		while(!stackL1.empty()||!stackL2.empty()){
			sum/=10;
 
			if(!stackL1.empty()){
				sum+=stackL1.top();
				stackL1.pop();
			}
 
			if(!stackL2.empty()){
				sum+=stackL2.top();
				stackL2.pop();
			}
			ListNode* node=new ListNode(sum%10);
			node->next=head;
			head=node;
		}
		//这个时判断链表都是空的了，但是还有进位的时候进行的运算
		if(sum>=10){
			ListNode* node=new ListNode(1);
			node->next=head;
			head=node;
		
	/*		head->next=node;	
			head=node;
			node->next=NULL;*/
		}
 
		return head;
    }
};
