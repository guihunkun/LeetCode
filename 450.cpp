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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        
        if(!root) return root;
        if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        TreeNode* left = root->left, *right = root->right, *tem = left;
        delete root;
        if(!left || !right) 
            return left?left: right;
        while(tem->right) 
            tem = tem->right;
        tem->right = right->left, right->left = left;
        return right;
    }
};
