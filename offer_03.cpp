class Solution 
{
public:
    int findRepeatNumber(vector<int>& nums) 
    {
        vector<int> rec(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            rec[nums[i]]++;
            if(rec[nums[i]] >= 2)
            {
                return nums[i];
            }
        }
        return -1;
    }
};
