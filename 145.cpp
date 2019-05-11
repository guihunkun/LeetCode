/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
    	postorder(root, res);
		return res; 
    }
    void postorder(TreeNode* root, vector<int> &res) 
	{
        if(root == NULL) 
			return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
};
*/
/*
class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;     
	    stack< pair<TreeNode *, bool> > s;
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
	            s.push(make_pair(root->right, false));
	            s.push(make_pair(root->left, false));
	        }
	    }
		return res;
    }
};
*/
class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;     
        if (root == NULL) 
			return res;
        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty()) 
		{
			TreeNode* node = sta.top();
			sta.pop();
            res.push_back(node->val);
            // 实现逆序
            if(node->left)
				sta.push(node->left);
            if(node->right)
				sta.push(node->right);
			
        }
        // 将结果进行逆序
        reverse(res.begin(), res.end());
		return res;
    }
};
