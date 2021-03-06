class Solution {
public:
    int mod = 1e9 + 7;
    int threeSumMulti(vector<int>& A, int target) {
        //dp[i][j][k]表示考虑前i个数时，从中选出j个数，组成k大小的方案数
        int n = A.size();
        int dp[n + 1][4][target + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i ++ ) dp[i][0][0] = 1;
        //这里要从1开始，因为前0个数是初始的条件
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= 3; j ++ )
                for (int k = 0; k <= target; k ++ )
                {
                    //这里用A[i - 1]是因为从1开始枚举下标，对于A数组来说，要从0开始，因此错后一个
                    if (k >= A[i - 1]) dp[i][j][k] =(dp[i][j][k] + dp[i - 1][j - 1][k - A[i - 1]]) % mod;
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k]) % mod;
                }
        
        //最终答案就是考虑前n个数时，选择其中3个数，组成target大小的方案数
        return dp[n][3][target];
    }
};

