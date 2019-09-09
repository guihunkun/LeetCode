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
    int rootexclude(TreeNode* root)
    {
        if(root==NULL) return 0;
        return rob(root->left)+rob(root->right);
    }
    int rootinclude(TreeNode* root)
    {
        if(root==NULL) return 0;
        return rootexclude(root->left)+rootexclude(root->right)+root->val;
    }
    int rob(TreeNode* root) 
    {
        if(root==NULL) return 0;
        return max(rootinclude(root),rootexclude(root));
    }  
};








/*

class Solution {
        int walk(TreeNode* root,int&val)
        {
            val=0;
            if(root==NULL)
                return 0;
            int left,right;
            val=walk(root->left,left)+walk(root->right,right);
            return max(val,left+right+root->val);   
      }
public:
    int rob(TreeNode* root) {
        int val;
        return walk(root,val);//这里采用引用传参的方式记录决策路径
    }
};
*/
