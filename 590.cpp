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
class Solution 
{
public:
    vector<int> postorder(Node* root) 
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
            for(int i = 0; i < node->children.size(); i++)
                sta.push(node->children[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
*/
class Solution 
{
public:
    vector<int> postorder(Node* root) 
    {
        vector<int> res;     
	    stack< pair<Node*, bool> > s;
	    s.push(make_pair(root, false));
	    bool visited;
	    while(!s.empty())
	    {
	        root = s.top().first;
	        visited = s.top().second;
	        s.pop();
	        if(root == NULL)
	            continue;
	        if(visited)
	        {
	            res.push_back(root->val);
	        }
	        else
	        {
	            s.push(make_pair(root, true));
                for(int i = root->children.size() - 1; i >= 0; i--)
                    s.push(make_pair(root->children[i],false));
	        }
	    }
		return res;
    }
};
