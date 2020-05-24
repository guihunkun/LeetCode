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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return construct(nums, 0, nums.size());
    }
    TreeNode* construct(vector<int>& nums, int l, int r) 
    {
        if(l == r)
            return NULL;
        int max_i = max(nums, l, r);
        TreeNode* root = new TreeNode(nums[max_i]);
        root->left = construct(nums, l, max_i);
        root->right = construct(nums, max_i + 1, r);
        return root;
    }
    int max(vector<int>& nums, int l, int r) 
    {
        int max_i = l;
        for(int i = l; i < r; i++) 
        {
            if(nums[max_i] < nums[i])
                max_i = i;
        }
        return max_i;
    }
};
