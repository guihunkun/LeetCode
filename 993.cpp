/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void DFS(TreeNode* root, map<int,pair<int,int>>& tmp, int k, int root_val)
    {
        if(root)
        {
            tmp[root->val]=make_pair(k,root_val);
            DFS(root->left, tmp, k+1, root->val);
            DFS(root->right,tmp, k+1, root->val);
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) 
    {
        map<int,pair<int,int>> tmp;
        if(root)
        {
            DFS(root->left, tmp, 1, root->val);
            DFS(root->right, tmp, 1, root->val);
        }
        if(tmp[x].first==tmp[y].first && tmp[x].second!=tmp[y].second)
            return true;
        return false;       
    }
};

