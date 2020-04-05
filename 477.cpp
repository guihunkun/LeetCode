/*
class Solution 
{
public:
    int totalHammingDistance(vector<int>& nums) 
    {
        if (nums.empty())
            return 0;

    int ans = 0, n = nums.size();
    vector<int> cnt(32, 0); // count of elements with a particular bit ON

    for(auto num : nums) 
    {   // loop over every element
        int i = 0;
        while(num > 0) 
        {           // check every bit
            cnt[i] += (num & 0x1);
            num >>= 1;
            i++;
        }
    }

    for(auto&& k : cnt) 
    {   // loop over every bit count
        ans += k * (n - k);
    }

    return ans;
    }
};
*/
class Solution 
{
public:
    int totalHammingDistance(vector<int>& nums) 
    {
        if(nums.empty())
            return 0;
        int res = 0;
        for(int i = 0; i < 32; ++i) 
        {
            int count = 0;
            int mask = 1 << i;
            for(int n : nums) {
                if (n & mask) 
                {
                    ++count;
                }
            }
            res += count * (nums.size() - count);
        }
        return res;
    }
};

