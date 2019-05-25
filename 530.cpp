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
    int getMinimumDifference(TreeNode* root)
    {
        vector<int> nums;
        inorder(root, nums);
        return Difference(nums);
    }
    void inorder(TreeNode* root, vector<int>& nums)
    {
        if(root == NULL)
            return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    int Difference(vector<int>& nums)
    {
        int num = nums[1] - nums[0];
        for(int i = 1; i < nums.size() - 1; i++)
            num = min(num, nums[i + 1] - nums[i]);
        return num;
        
    }
};
