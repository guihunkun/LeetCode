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
    int maxPathSum(TreeNode* root, int &val)
    {
        if (root == nullptr) 
            return 0;
        int left = maxPathSum(root->left, val);
        int right = maxPathSum(root->right, val);
        int lmr = root->val + max(0, left) + max(0, right);
        int ret = root->val + max(0, max(left, right));
        val = max(val, max(lmr, ret));
        return ret;
    }

    int maxPathSum(TreeNode* root) 
    {
        int val = INT_MIN;
        maxPathSum(root, val);
        return val;
    }
};
