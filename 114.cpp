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
    void flatten(TreeNode* root) 
    {
        if(root!=NULL)
        {
            if(root->left==NULL && root->right!=NULL)
                flatten(root->right);
            else if(root->left!=NULL && root->right==NULL)
            {
                flatten(root->left);
                root->right=root->left;
                root->left=NULL;
            }
            else if(root->left!=NULL && root->right!=NULL)
            {
                flatten(root->left);
                flatten(root->right);
                TreeNode* temp=root->left;
                while(temp->right!=NULL)
                    temp=temp->right;
                temp->right=root->right;
                root->right=root->left;
                root->left=NULL;
            } 
            
        }   
    }
};

