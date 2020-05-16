class Solution 
{
public:

    int kInversePairs(int n, int k) 
    {
        vector<vector<int64_t>> dp(n + 1, vector<int64_t>(k + 1, 0));
        for(int i = 0; i <= n; ++i)
            dp[i][0] = 1;
        for(int i = 2; i <= n; ++i)
            for (int t = 1; t <= k; ++t)
                dp[i][t] = t >= i ? 
                (dp[i - 1][t] + dp[i][t - 1] - dp[i - 1][t - i] + 1000000007) % 1000000007 : 
                (dp[i - 1][t] + dp[i][t - 1]) % 1000000007;
        return dp.back().back();
    }

};
