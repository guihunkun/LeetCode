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
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> record;
        inorder(root, record);
        int left = 0, right = record.size() - 1;
        while(left < right)
        {
            int sum = record[left] + record[right];
            if(sum == k)
                return true;
            if(sum < k)
                left++;
            else
                right--;
        }
        return false;
    }
    void inorder(TreeNode* root, vector<int>& record)
    {
        if(root == NULL)
            return;
        inorder(root->left, record);
        record.push_back(root->val);
        inorder(root->right, record);
    }
};
*/
class Solution 
{
public:
    bool findTarget(TreeNode* root, int k) 
    {
        set<int> record;
        return find(root, k, record);
    }
    bool find(TreeNode* root, int k, set<int>& record)
    {
        if(root == NULL)
            return false;
        if(record.find(k - root->val) != record.end())
            return true;
        record.insert(root->val);
        return find(root->left, k, record) || find(root->right, k, record);
    }
};
