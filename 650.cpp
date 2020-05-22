/*
class Solution 
{
public:
    int minSteps(int n) 
    {
        vector<int> dp(n + 1, 0);
        for(int i = 2; i < n + 1; i++) 
        {
            int minCount = INT_MAX;
            for(int j = 1; j < i; j++)
            {
                if(i % j == 0) 
                {
                    minCount = min(dp[j] + i / j, minCount);
                }
            }
            dp[i] = minCount;
        }
        return dp[n];
    }
};
*/

class Solution 
{
public:
    int minSteps(int n) 
    {
        int ans = 0, d = 2;
        while(n > 1) 
        {
            while(n % d == 0) 
            {
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
};
