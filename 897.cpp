/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) 
    {
        if(root == NULL)
            return root;
        vector<int> rec;
        inorder(root, rec);
        TreeNode* p = new TreeNode(-1);
        TreeNode* head = p;
        for(int i = 0; i < rec.size(); i++)
        {
            p->left=NULL;
            TreeNode* t = new TreeNode(rec[i]);
            p->right = t;
            p = t;
        }
        return head->right;

    }
    void inorder(TreeNode* node, vector<int>& rec) 
    {
        if(node == NULL)
            return;
        inorder(node->left, rec);
        rec.push_back(node->val);
        inorder(node->right, rec);
    }
};
*/

class Solution 
{
public:
    TreeNode* p;
    TreeNode* increasingBST(TreeNode* root) 
    {
        if(root == NULL)
            return root;
        p = new TreeNode(-1);
       TreeNode* head = p;
       _increasingBST(root);
       return head->right;
    }
    void _increasingBST(TreeNode* root)
    {
        if(root->left != NULL)
        {
            _increasingBST(root->left);
        }
        p->left == NULL;
        TreeNode* t = new TreeNode(root->val);
        p->right = t;
        p = t;
        if(root->right != NULL)
        {
            _increasingBST(root->right);
        }
    }
};
