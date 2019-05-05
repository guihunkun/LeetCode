class Solution 
{
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        if(nums.size() <= 1)
            return 0;
        int min_num = INT_MAX, max_num = INT_MIN;
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] < nums[i-1])
                min_num = min(min_num, nums[i]);
        for( int i = nums.size()-2;i >= 0; i--)
            if(nums[i] > nums[i+1])
                max_num = max(max_num, nums[i]);
        int l,r;
        for(l = 0; l < nums.size(); l++)
            if(min_num < nums[l])
                break;
        for( r = nums.size()-1; r >= 0; r--)
            if(max_num > nums[r])
                break;
        return r-l < 0 ? 0 : r-l+1; 
    }
};
