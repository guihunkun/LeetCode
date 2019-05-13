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
    int sumRootToLeaf(TreeNode* root)
    {
        return sumLeaf(0, root);
    }
    int sumLeaf(int val, TreeNode* root)
    {
        int cur = (val << 1) + root->val;
        int sum = 0;
        if(root->left == NULL && root->right == NULL)
            return cur;
        if(root->left)
            sum = sumLeaf(cur, root->left);
        if(root->right)
            sum += sumLeaf(cur, root->right);
        return sum;
    }
};
