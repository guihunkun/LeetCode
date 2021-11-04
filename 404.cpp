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
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        long long sumleft = 0;
        if(root->left && root->left->left == NULL && root->left->right == NULL) {
            sumleft += root->left->val;
        }
        if(root->left)
            sumleft += sumOfLeftLeaves(root->left);
        if(root->right)
            sumleft += sumOfLeftLeaves(root->right);
        return sumleft;
    }
};
