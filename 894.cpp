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
    vector<TreeNode*> allPossibleFBT(int N) 
    {
        if(N%2 == 0)
            return {};
        if(N == 1)
            return {new TreeNode(0)};
        vector<TreeNode*> ans;
        for(int lef = 1; lef + 1 < N; lef++)
        {
            vector<TreeNode*> left = allPossibleFBT(lef);
            vector<TreeNode*> right = allPossibleFBT(N-1-lef);
            for(TreeNode* l : left)
            {
                for(TreeNode* r : right)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

};
