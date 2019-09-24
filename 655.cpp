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
    vector<vector<string>> printTree(TreeNode* root) 
    {
        int height = get_height(root);
        int width = pow(2, height) - 1;
        vector<vector<string>> vec(height, vector<string>(width, ""));
        helper(vec, root, 0, 0, width);
        return vec;
    }

    int get_height(TreeNode* root) 
    {
        if (!root)
            return 0;
        int left = get_height(root->left);
        int right = get_height(root->right);
        return max(left, right) + 1;
    }

    void helper(vector<vector<string>> & ans, TreeNode* root, int level, int l, int r) 
    {
        if (root != NULL) 
        {
            int mid = l + (r - l) / 2;
            ans[level][mid] = to_string(root->val);
            helper(ans, root->left, level + 1, l, mid - 1);
            helper(ans, root->right, level + 1, mid + 1, r);
        }
    }
};
