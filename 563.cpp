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
    int tilt;
public:
    int findTilt(TreeNode* root) 
    {
        tilt = 0;
        help(root);
        return tilt;
    }
    int help(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int L = help(root->left);
        int R = help(root->right);
        tilt += abs(L - R);
        return L + R + root->val;
    }
};
