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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int> > res;
        if(root == NULL)   
            return res;  
        queue<TreeNode*> q;     
        q.push(root);
        int level = 0;
        while( !q.empty() ) 
        {  
            vector<int> tmp;
            int count = q.size();
            for(int i = 0; i < count; i++)
            {
                TreeNode *t=q.front();             
                q.pop();    
                if(level%2 == 0) 
                    tmp.push_back(t->val);
                else
                    tmp.insert(tmp.begin(),t->val);
                if(t->left)     
                    q.push(t->left);
                if(t->right)    
                    q.push(t->right);
            }
            level++;
            res.push_back(tmp);
        }
        return res;
    }
};
