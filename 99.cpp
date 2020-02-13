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
    void recoverTree(TreeNode* root) 
    {
        vector<TreeNode*>vec;
        TreeNode* pre=NULL;
        recoverTree(root,vec,pre);
        if(vec.size()==2)
        {
            int temp=vec[0]->val;
            vec[0]->val=vec[1]->val;
            vec[1]->val=temp;
        }
        else
        {
            int temp=vec[0]->val;
            vec[0]->val=vec[2]->val;
            vec[2]->val=temp;
        }
    }
    void recoverTree(TreeNode* root,vector<TreeNode*>& vec,TreeNode*& pre)
    {
        if(!root) 
            return;
        recoverTree(root->left,vec,pre);
        if(pre&&vec.size()==0)
        {
            if(root->val<pre->val)
            {
                vec.push_back(pre);
                vec.push_back(root);
            }
        }
        else if(vec.size()==2&&(pre&&root->val<pre->val)) 
            vec.push_back(root);
        pre=root;
        recoverTree(root->right,vec,pre);
    }
};
