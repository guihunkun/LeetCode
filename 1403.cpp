class Solution 
{
public:
    vector<int> minSubsequence(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0;
        for(auto num : nums)
        {
            sum += num;
        }
        int cur = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            cur += nums[i];
            if(cur > sum-cur)
            {
                return vector<int>(nums.begin(), nums.begin()+i+1);
            }

        }
        return nums;
    }
};
