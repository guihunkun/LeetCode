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
    TreeNode* convertBiNode(TreeNode* root) 
    {
        TreeNode* head = new TreeNode(-1);
        TreeNode* cur = head;
        inorderTraversal(root, cur);
        return head->right;
    }
    void inorderTraversal(TreeNode* root, TreeNode* &cur) 
    { //中序遍历
        if(root) 
        {
            inorderTraversal(root->left, cur);
            cur->right = root; //将此节点赋给cur的右子树
            root->left = NULL; //将此节点的左子树赋值NULL
            cur = root; //更新
            inorderTraversal(root->right, cur);
        }
    }
};
