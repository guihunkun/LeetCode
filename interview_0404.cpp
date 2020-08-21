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
    bool isBalanced(TreeNode* root) 
    {
        if(root == NULL)
        {
            return true;
        }
        if(abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int maxDepth(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
