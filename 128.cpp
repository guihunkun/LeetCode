/*
class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int, int> dp;
        int ret = 0;
        for(auto &x : nums) 
        {
            if(!dp[x]) 
                dp[x - dp[x - 1]] = dp[x + dp[x + 1]] = dp[x] = dp[x - 1] + dp[x + 1] + 1;
            ret = max(ret, dp[x]);
        }
        return ret;
    }
};
*/


class Solution 
{
public:
    unordered_map<int, int> F;
    int father(int x) 
    {
        if(F.count(x) == 0)
            return x;
        if(F[x] != x)
            F[x] = father(F[x]);
        return F[x];
    }
    int longestConsecutive(vector<int>& nums) 
    {
        F.clear();
        for(auto x : nums) 
        {
            F[x] = father(x);
            if(F.count(x - 1) > 0)
                F[father(x - 1)] = father(x);
            if(F.count(x + 1) > 0)
                F[father(x)] = father(x + 1);
        }
        int res = 0;
        for(auto x : nums)
            if(father(x) - x + 1 > res)
                res = father(x) - x + 1;
        return res;
    }
};


