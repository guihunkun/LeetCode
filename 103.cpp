/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
		vector<vector<int>> ans;
		if(!root)	
            return ans;
		stack<TreeNode*> s1, s2;
		s1.push(root);
		TreeNode* t;
		int cur;
		while(!s1.empty() || !s2.empty()) 
        {
			if(!s1.empty()) 
            {
				cur = ans.size();
				ans.push_back(vector<int>());
			    while(!s1.empty()) 
                {
					t = s1.top();
					s1.pop();
					if(t) {
						ans[cur].push_back(t->val);
						s2.push(t->left);
						s2.push(t->right);
					}
				}
			}
			else if(!s2.empty()) 
            {
				cur = ans.size();
				ans.push_back(vector<int>());
				while(!s2.empty()) 
                {
					t = s2.top();
					s2.pop();
					if(t) 
                    {
						ans[cur].push_back(t->val);
						s1.push(t->right);
						s1.push(t->left);
					}
				}
			}
		}
		ans.pop_back();		// 由于最后的栈中一定全是nullptr所以ans的最后一个元素一定是[]，需要去掉
		return ans;
	}
};
