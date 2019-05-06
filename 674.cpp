class Solution 
{
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        int res = 1, coc = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
                coc++;
            else
            {
                res = max(coc, res);
                coc = 1;
            }
        }
        return max(res, coc);
    }
};
