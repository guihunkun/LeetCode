class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int res = 0, now = 0;
        if(nums.size() == 0 )
            return 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
                now++;
            res = max(res, now);
            if(nums[i] == 0)                
                now = 0;
        }
        return res;
    }
};
