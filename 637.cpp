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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> numsage;
        vector<vector<int> > res;
        vector<int> r;
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
        for(int i = 0; i < res.size(); i++)
        {
            double ave = 0;
            int j = 0;
            for(; j < res[i].size(); j++)
                ave += res[i][j];
            numsage.push_back(ave / (j));
        }
        return numsage;
    }
};
