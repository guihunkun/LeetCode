class Solution 
{
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int sum = 0, maxsum = 0;
        // for(int i = 0; i < nums.size(); i++)
        //     sum += nums[i];
        // if(nums.size() <= k)
        //     return sum*1.0/nums.size();
        for(int i = 0; i < k; i++)
            maxsum += nums[i];
        sum = maxsum;
        for(int i = k; i < nums.size(); i++)
        {
            sum += nums[i];
            sum =sum - nums[i-k];
            maxsum = max(maxsum, sum);
        }
        return maxsum*1.0/k;
    }
};
