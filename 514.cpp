//动态规划
//dp[i][j]，key的0~i位字符拼写后，ring的第j位对齐12：00方向，需要的最小步数
//前提：key[i] = ring[j]，若不满足，dp[i][j] = INT_MAX
class Solution 
{
public:
    int findRotateSteps(string ring, string key) 
    {
        int m = ring.size(), n = key.size(), cost = 0;
        vector<vector<int> > dp(n, vector<int>(m,0));
        for(int j = 0; j < m; j++)
            if(ring[j] == key[0])
                dp[0][j] = min(j + 1, m - j + 1);
        for(int i = 1; i < n; i++){ //key[i]
            for(int j = 0; j < m; j++)
            { //当前ring12:00在j
                dp[i][j] = INT_MAX;
                if(ring[j] != key[i]) 
                    continue;
                for(int k = 0; k < m; k++){ //上一次ring12:00在k
                    if(ring[k] != key[i - 1]) 
                        continue;
                    cost = dp[i - 1][k] + min((j - k + m) % m, (k - j + m) % m) + 1;
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        int mincost = INT_MAX;
        for(int j = 0; j < m; j++)
            if(ring[j] == key[n - 1])
                mincost = min(mincost, dp[n - 1][j]);
        return mincost;
    }
};
