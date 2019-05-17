class Solution 
{
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if(n == 0)
            return 1;
  
        vector<int> dp(11);
        dp[0] = 0;
        dp[1] = 10;
        dp[2] = 9*9;
        dp[3] = 9*9*8;
        dp[4] = 9*9*8*7;
        dp[5] = 9*9*8*7*6;
        dp[6] = 9*9*8*7*6*5;
        dp[7] = 9*9*8*7*6*5*4;
        dp[8] = 9*9*8*7*6*5*4*3;
        dp[9] = 9*9*8*7*6*5*4*2;
        dp[10] = 9*9*8*7*6*5*4*3*2*1;
        if(n > 10)
            return dp[0];
        int sol = 0;
        for(int i = 0 ; i <= n ;i++)
            sol += dp[i];
        return sol; 
    }
};
