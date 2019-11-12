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
    TreeNode* helperPreIn(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend)
	{
		if(prestart > preend || instart > inend)
		{
			return NULL;
		}

		TreeNode* node =new TreeNode(preorder[prestart]);
		int i;
		for(i = instart; i <= inend; i++)
		{
			if(inorder[i] == node->val)
			{
				break;
			}
		}

		node->left=helperPreIn(preorder, inorder, prestart + 1, prestart + i - instart, instart, i - 1);
		node->right=helperPreIn(preorder , inorder, prestart + i - instart + 1, preend, i + 1, inend);
		return node;
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return helperPreIn(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
