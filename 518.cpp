class Solution 
{
public:
    int change(int amount, vector<int>& coins) 
    {
        int dp[amount+1];
        memset(dp, 0, sizeof(dp)); //初始化数组为0
        dp[0] = 1;
        for(int coin : coins)
        { //枚举硬币
            for(int i = 1; i <= amount; i++)
            { //枚举金额
                if(i < coin) 
                    continue; // coin不能大于amount
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};
