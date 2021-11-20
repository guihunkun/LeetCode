/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int> > levelOrder(TreeNode* root) 
    {
        //层序遍历
        vector<vector<int> > res;
        vector<int> r;
        if(root==NULL)
            return  res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
        	r.clear();
        	int count = q.size();
        	while(count > 0)
        	{
        		TreeNode* node=q.front();
        		r.push_back(node->val);
        		q.pop();
        		count--;
        		if(node->left)
                	q.push(node->left);
            	if(node->right)
                	q.push(node->right);
			}
            res.push_back(r);           
        }
        return res;
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        
        vector<int> res;
        if(root == NULL)
            return res;
        vector<vector<int> > record = levelOrder(root) ;
        for(int i = 0; i < record.size(); i++) {
            res.push_back(record[i][record[i].size() - 1]);
        }
        return res;
    }
};
