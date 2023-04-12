/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution 
{
public:
    int flag = 1; 
    Node* connect(Node* root) 
    {
        if(!root)
            return nullptr;
        if(flag) {
            // 将根节点next置为null
            root->next = nullptr;
            flag = 0;
        } 
        if(!root->left) 
            return root;
        root->left->next = root->right;
        if(root->next)
            root->right->next = root->next->left;
        else 
            root->right->next = nullptr;
        connect(root->left);
        connect(root->right);
        return root;
    }
};

