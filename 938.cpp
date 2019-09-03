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
    int res = 0;
public:
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        dfs(root, L, R);
        return res;
    }
    void dfs(TreeNode* root, int L, int R)
    {
        if(root != NULL)
        {
            if(L <= root->val && root->val <= R)
                res += root->val;
            if(L < root->val)
                dfs(root->left, L, R);
            if(root->val < R)
                dfs(root->right, L, R);
        }
    }
};
