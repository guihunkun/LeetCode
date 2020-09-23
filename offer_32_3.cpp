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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int> > res;
        if(root == nullptr) 
        {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty()) 
        {
            int num = q.size();
            vector<int> tmp;
            for(int i = 0; i < num; i++) 
            {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left != nullptr) {
                    q.push(node->left);
                }
                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if((i++%2) == 0) 
            {
                reverse(tmp.begin(), tmp.end());
            }    
            res.push_back(tmp);
        } 
        return res;
    }
};
