/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution 
{
public:
    Node* flatten(Node* head) 
    {
        if(!head)
            return nullptr;
        Node *cur=head;
        while(cur)
        {
            Node *nxt=cur->next;
            if(cur->child)
            {
                //1、存在孩子节点，将child与cur之间的孩子连接改为双向连接
                Node * _child=cur->child;
                cur->next=_child;
                _child->prev=cur;
                cur->child=nullptr;
                //2、获取child这一子链表的尾节点，便于插入到cur的后面
                Node *tail=_child;
                while(tail&&tail->next)
                {
                    tail=tail->next;
                }
                //3、将[child,tail]这段链表插入到cur和nxt之间的位置
                tail->next=nxt;
                if(nxt)
                {
                    nxt->prev=tail;
                }
            }
            cur=cur->next;
        }
        return head;
    }
};
