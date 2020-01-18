/*
class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0]; 
        for(int i = 1; i < nums.size(); i++)
        {
            sum[i] = sum[i-1] + nums[i];
        }
        for(int l = 0; l < sum.size() - 1; l++)
        {
            for(int r = l + 1; r < sum.size(); r++)
            {
                int tar = sum[r] - sum[l] + nums[l];
                if(tar == k || (k != 0 && tar%k == 0))
                    return true; 
            }
        }
        return false;
    }
};
*/
class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        map<int, int> rec;
        rec[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {    
            sum += nums[i];
            if(k != 0)
            {
                sum = sum%k;
            }
            if(rec.find(sum) != rec.end())
            {
                if(i - rec[sum] > 1)
                    return true;
            }
            else
            {
                rec[sum] = i;
            }
        }
        return false;
    }
};
