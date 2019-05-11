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
class Solution 
{
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int> > res;
        vector<int> r;
        if(root==NULL)
            return  res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            r.clear();
            int count = q.size();
            while(count > 0)
            {
                Node* node = q.front();
                r.push_back(node->val);
                q.pop();
                count--;
                if(node->children.size() != 0)
                    for(int i =0; i < node->children.size(); i++)
                        q.push(node->children[i]);
            }
            res.push_back(r);
        }
        return res;
    }
};
