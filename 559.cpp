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
    int maxDepth(Node* root) 
    {
        int max = 0;
        if(root==NULL)
            return 0;
        else if(root->children.size() == 0)
            return 1;
        else
        {
            for(int i = 0; i < root->children.size(); i++)
            {
                int depth = maxDepth(root->children[i]);
                max = max > depth ? max : depth;
            }
            return max + 1;
                
        }
        return  max;
    }
};
