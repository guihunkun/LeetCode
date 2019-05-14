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
    vector<TreeNode*> generateTrees(int n) 
    {
        vector<TreeNode*> res;
        if(n == 0)
            return res;
        return generateTree(1,n);
    }
    vector<TreeNode*> generateTree(int left, int right)
    {
        vector<TreeNode*> res;
        if(left > right)
            res.push_back(NULL);
        else
        {
            for(int i = left; i <= right; i++)
            {
                vector<TreeNode*> leftsubTree = generateTree(left, i - 1);
                vector<TreeNode*> rightsubTree = generateTree(i + 1, right);
                for(int j = 0; j < leftsubTree.size(); j++)
                    for(int k = 0; k < rightsubTree.size(); k++)
                    {
                        TreeNode* node = new TreeNode(i);
                        node->left = leftsubTree[j];
                        node->right = rightsubTree[k];
                        res.push_back(node);
                    }
                        
            }      
        }
        return res;
    }
};
