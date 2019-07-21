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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        vector<TreeNode*> res;
        deleteNode(root, to_delete, res, true);
        return res;
    }
private:
    TreeNode* deleteNode(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& res, bool no_parent) 
    {
        if (!root) 
            return root;
        auto it = find(to_delete.begin(), to_delete.end(), root->val);
        bool td = it != to_delete.end();
        if (!td && no_parent) 
        {
            res.push_back(root);
        }
        root->left = deleteNode(root->left, to_delete, res, td);
        root->right = deleteNode(root->right, to_delete, res, td);
        
        return td? nullptr : root;
    }  
};