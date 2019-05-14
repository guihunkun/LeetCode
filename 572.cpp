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
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if(s == NULL)
            return false;
        if(IsSame(s, t))
            return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool IsSame(TreeNode* s, TreeNode* t) 
    {
        if(s == NULL && t == NULL)
            return true;
        if(s == NULL || t == NULL)
            return false;
        return s->val == t->val && IsSame(s->left, t->left) && IsSame(s->right, t->right);
    }
};
