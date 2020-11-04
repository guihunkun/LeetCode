class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        if(nums.empty())
        {
            return -1;
        }
        int pre = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            pre = max(pre + nums[i], nums[i]);
            res = max(res, pre);
        }
        return res;
    }
};
