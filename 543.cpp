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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        res = 1;
        depth(root);
        return res - 1;
    }
    int depth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        res = max(res, L + R + 1);
        return max(L, R) + 1;
    }
};
