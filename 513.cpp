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
    int maxlevel = 0;
    int res = 0;
    int findBottomLeftValue(TreeNode* root) 
    {
        helper(root, 1);
        return res;
    }
    void helper(TreeNode* root, int level)
    {
        if(root == NULL)
        {
            return ;
        }
        helper(root->left, level+1);

        if(level > maxlevel)
        {
            res = root->val;
            maxlevel = level;
        }
        helper(root->right, level+1);
    }
};
