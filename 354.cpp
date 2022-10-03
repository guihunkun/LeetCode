class Solution 
{
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
    }
    //题解1：动态规划，时间复杂度O(n^2)，空间复杂度O(n)
    int maxEnvelopes_1(vector<vector<int>>& envelopes) 
    {
        if(envelopes.empty())
            return 0;
        //先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
        sort(envelopes.begin(),envelopes.end(), cmp);
        int n=envelopes.size(),res=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(envelopes[j][1]<envelopes[i][1])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }

    //优化：动态规划+二分法，时间复杂度O(nlogn)，空间复杂度O(n)
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        if(envelopes.empty())return 0;
        //先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
        sort(envelopes.begin(),envelopes.end(), cmp);
        vector<int> dp;
        for(auto& en:envelopes)
        {
            int idx=lower_bound(dp.begin(),dp.end(),en[1])-dp.begin();
            if(idx>=dp.size())
            {
                dp.emplace_back(en[1]);
            }
            else
            {
                dp[idx]=en[1];
            }
        }
        return dp.size();
    }
};
