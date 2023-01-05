/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution 
{
public:
    Node* count(Node *head,Node* test,Node* tete)
    {
        Node *move=head;
        int c=0;
        int i=0;
        while(move!=test)
        {
            c++;
            move=move->next;
        }//求到random-index等于c
        while(i!=c)
        {
            tete=tete->next;
            i++;
        }//在新构造的链表中迭代c次，对应节点就是新表中random应该指向的结点
        return tete;
    }
    Node* copyRandomList(Node* head) 
    {
        if(head==NULL) 
            return head;
        Node *tete=new Node(head->val);
        Node *m=head;
        Node *n=tete;
        while(m->next!=NULL)
        {
            Node *tmp=new Node(m->next->val);
            n->next=tmp;
            n=n->next;
            m=m->next;
        }//构造好了新链表
        m=head;
        n=tete;
        while(m!=NULL)
        {
            n->random=count(head,m->random,tete);//关键的一步，同步random
            m=m->next;
            n=n->next;
        }
        return tete;
    }
};


