class Solution 
{
public:
    int specialArray(vector<int>& nums) 
    {
        int res = -1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= nums[nums.size()-1]; i++)
        {
            auto iter = lower_bound(nums.begin(), nums.end(), i);
            int count = nums.end()-iter;
            if(count == i) {
                res = i;
            }
        }
        return res;
    }
};
