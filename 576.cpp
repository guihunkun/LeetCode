class Solution 
{
public:
    int findPaths(int m, int n, int N, int i, int j) 
    {
        if(N == 0)
            return 0;
        long dp[N][m + 2][n + 2];
        memset(dp, 0, sizeof(dp));
        dp[0][i + 1][j + 1] = 1;
        long int res = 0;
        if(i == 0)
            res++;
        if(i == m - 1)
            res++;
        if(j == 0)
            res++;
        if(j == n - 1)
            res++;

        for(int t = 1; t < N; t++) 
        {
            for(int mi = 1; mi <= m; mi++) 
            {
                for(int ni = 1; ni <= n; ni++) 
                {
                    dp[t][mi][ni] = dp[t - 1][mi - 1][ni] + dp[t - 1][mi + 1][ni]
                                    + dp[t - 1][mi][ni - 1] + dp[t - 1][mi][ni + 1];
                    dp[t][mi][ni] %= 1000000007;
                    if(mi == 1)
                        res += dp[t][mi][ni];
                    if(mi == m)
                        res += dp[t][mi][ni];
                    if(ni == 1)
                        res += dp[t][mi][ni];
                    if(ni == n)
                        res += dp[t][mi][ni];
                    res %= 1000000007;
                }
            }
        }
        return int(res);
    }
};
