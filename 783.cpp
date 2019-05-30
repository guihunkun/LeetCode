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
    int minDiffInBST(TreeNode* root) 
    {
        int res = INT_MAX;
        vector<int> record;
        inorder(root, record);
        for(int i = 1; i < record.size(); i++)
            res = min(res, record[i] - record[i - 1]);
        return res;
    }
    void inorder(TreeNode* root, vector<int>& record)
    {
        if(root == NULL)
            return;
        inorder(root->left, record);
        record.push_back(root->val);
        inorder(root->right,record);
    }
};
