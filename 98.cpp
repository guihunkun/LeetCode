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
    void inorder(vector<int> & record, TreeNode * root)
    {
        if(root)
        {
            inorder(record, root->left);
            record.push_back(root->val);
            inorder(record, root->right);
        }
    }
    bool isValidBST(TreeNode* root) 
    {
        vector<int> record;
        inorder(record, root);
        if(record.size() == 0)
            return true;
        else
        {
            for(int i = 1; i < record.size(); i++)
                if(record[i] <= record[i - 1])
                    return false;
            return true;
        }
    }
};
