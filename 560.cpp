class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int sum = 0, res = 0;
        unordered_map<int, int> rec;
        rec[0] = 1;
        for(auto num : nums)
        {
            sum += num;
            if(rec.find(sum -k) != rec.end())
            {
                res += rec[sum-k];
            }
            rec[sum]++;
        }
        return res;
    }
};
