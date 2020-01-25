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
    int dfs(TreeNode* root, unordered_map<int, int>& m, int& max_count) 
    {
        if(root == NULL) 
            return 0;
        int l = dfs(root->left, m, max_count);
        int r = dfs(root->right, m, max_count);
        int s = l + r + root->val;
        max_count = max(max_count, ++m[s]);
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        int max_count = 0;
        unordered_map<int, int> m;
        dfs(root, m, max_count);
        vector<int> res;
        for(auto& p : m) 
        {
            if(p.second == max_count) 
            {
                res.push_back(p.first);
            }
        }
        return res;
    }
};
