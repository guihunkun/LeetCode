class Solution 
{
public:
    int minDistance(vector<int>& houses, int K) 
    {
        sort(houses.begin(), houses.end());
        int n = houses.size();
        vector<vector<int>> rec(n, vector<int>(n, 0));
        for(int i = 0; i < n; i ++)
        {
            for(int j = i; j < n; j ++)
            {
                int mid = i + j >> 1;
                for(int k = i; k <= j; k ++) {
                    rec[i][j] += abs(houses[k] - houses[mid]);
                }
            }
        }
        vector<vector<int>> dp(n, vector<int>(K + 1, 2e9));
        for(int i = 0; i < n; i ++) {
            dp[i][1] = rec[0][i];
        }
        for(int i = 0; i < n; i ++){
            for(int j = 2; j <= min(i + 1, K); j ++){
                for(int k = j - 1; k <= i; k ++){
                    dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + rec[k][i]);
                }
            }
        }
        return dp[n-1][K];
    }
};
