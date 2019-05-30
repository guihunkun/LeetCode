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
    int res;
public:
    int longestUnivaluePath(TreeNode* root) 
    {
        res = 0;
        arrowLength(root);
        return res;
    }
    int arrowLength(TreeNode* root)
    {
        if(root ==NULL)
            return 0;
        int left = arrowLength(root->left);
        int right = arrowLength(root->right);
        int arrowLeft = 0, arrowRight = 0;
        if(root->left != NULL && root->left->val == root->val)
            arrowLeft += left + 1;
        if(root->right != NULL && root->right->val == root->val)
            arrowRight += right + 1;
        res = max(res, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    }
};
