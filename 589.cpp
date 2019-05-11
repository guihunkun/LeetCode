/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*
class Solution {
public:
    vector<int> preorder(Node* root) 
    {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    void preorder(Node* root, vector<int> &res)
    {
        if(root)
        {
            res.push_back(root->val);
            for(int i = 0; i < root->children.size(); i++)
                preorder(root->children[i],res);
        }
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) 
    {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<Node*> sta;
        sta.push(root);
        while(!sta.empty())
        {
            Node* node = sta.top();
            sta.pop();
            res.push_back(node->val);
            for(int i = node->children.size()-1; i >= 0; i--)
                sta.push(node->children[i]);
        }
        return res;
    }
};

