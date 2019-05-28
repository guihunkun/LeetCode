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
    int num;
public:
    bool isUnivalTree(TreeNode* root) 
    {
        if(root == NULL)
            return false;
        num = root->val;
        return preorder(root, num);
    }
    bool preorder(TreeNode* root, int num)
    {
        if(root != NULL)
        {
            if(root->val != num)
                return false;
            return preorder(root->left, num) && preorder(root->right, num);
        }
        return true;    
    }
};
