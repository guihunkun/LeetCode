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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
    	inorder(root,res);
		return res;
    }
    void inorder(TreeNode* root, vector<int> &res) 
	{
        if(root == NULL)
			return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};
*/
class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root == NULL)
        	return res;
        stack<TreeNode*> sta;
        TreeNode* node = root;
		while(!sta.empty() || node != NULL)
		{
			while(node != NULL)
			{
				sta.push(node);
				node = node->left;	
			}	
			if(!sta.empty())
			{
				node = sta.top();
				sta.pop();
				res.push_back(node->val);
				node = node->right;
			}
		} 
		return res;
    }
};
