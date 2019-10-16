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
    string ans = "";
    void dfs(TreeNode* root, string& cur)
    {
        if(root == NULL)
            return ;
        cur += (root->val + 'a');
        if(root->left == NULL && root->right == NULL)
        {
            reverse(cur.begin(), cur.end());
            if(ans.size() == 0 || cur < ans)
            {
                ans = cur;
            }
            reverse(cur.begin(), cur.end());
        }
        dfs(root->left, cur);
        dfs(root->right, cur);
        cur.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) 
    {
        string cur = "";
        dfs(root, cur);
        return ans;
    }
};
