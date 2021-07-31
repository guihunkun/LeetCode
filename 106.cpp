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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int postart, int poend)
    {
        if(instart > inend || postart > poend)
            return NULL;
        TreeNode *node = new TreeNode(postorder[poend]);
        int i = 0;
        //遍历中序，找到树的根结点
        for(i = instart; i< inorder.size(); i++)
        {
            if(inorder[i] == node->val)
                break;
        }
        
        //i-instart是inorder中根结点到左边起始点的距离
        node->left = helper(inorder, postorder, instart, i - 1, postart, postart + i - instart - 1);
        node->right = helper(inorder, postorder, i + 1, inend , postart + i - instart, poend - 1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(inorder.size() == 0)
            return NULL;
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);    
    }
};


