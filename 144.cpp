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
    vector<int> preorderTraversal(TreeNode* root) 
	{
        vector<int> res;
        helper(root, res);
        return res;
    }
    
    void helper(TreeNode* root, vector<int> &res)
	{
		if(root == NULL) 
			return;
        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right,res);
	}
};
*/
class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
	{
        vector<int> res;
        if(root == NULL)
        	return res;
        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty())
        {
        	TreeNode* node = sta.top();
        	sta.pop();
        	res.push_back(node->val);
        	
			if(node->right)
				sta.push(node->right);
			if(node->left)
				sta.push(node->left);
		}
		return res;
    }
};


