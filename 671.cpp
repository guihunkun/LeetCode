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
    int min1;
    long long ans = LLONG_MAX;
public:
    void dfs(TreeNode* root)
    {
        if(root != NULL)
        {
            if(min1 < root->val && root->val <ans)
                ans = root->val;
            else if(min1 == root->val)
            {
                dfs(root->left);
                dfs(root->right);
            }
        }
    }
    int findSecondMinimumValue(TreeNode* root) 
    {
        if(root == NULL)
            return -1;
        min1 = root->val;
        dfs(root);
        return ans < LLONG_MAX ? (int)ans : -1;
        
    }
};
