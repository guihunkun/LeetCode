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
class Solution 
{
public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> res;
        if(root == NULL) 
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) 
        {
            int levelSize = q.size();
            int levelMax = INT_MIN;
            for(int i = 0; i < levelSize; i++) 
            {
                TreeNode* curNode = q.front();
                q.pop();
                levelMax = max(curNode->val, levelMax);
                if(curNode->left) 
                    q.push(curNode->left);
                if(curNode->right) 
                    q.push(curNode->right);
            }
            res.push_back(levelMax);
        }
        return res;
    }
};
*/
class Solution 
{
public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> res;
        if(root == NULL) 
            return res;
        helper(root, 0, res);
        return res;
    }
    void helper(TreeNode* root, int level, vector<int>& res)
    {
        if(root == NULL)
        {
            return ;
        }

        if(level == res.size())
        {
            res.push_back(root->val);
        }
        else
        {
            res[level] = max(res[level], root->val);
        }

        helper(root->left, level+1, res);
        helper(root->right, level+1, res);
    }
};
