class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int N1 = s1.size();
        int N2 = s2.size();
        int N3 = s3.size();
        if (N1 + N2 != N3) return false;
        vector<bool> dp(N2 + 1, false);
        dp[0] = true;
        for(int i = 0; i <= N1; ++i) 
        {
            for(int j = 0; j <= N2; ++j) 
            {
                if(i > 0 && s1[i - 1] != s3[i + j - 1]) 
                {
                    dp[j] = false;
                }
                if(j > 0 && s2[j - 1] == s3[i + j - 1]) 
                {
                    dp[j] = dp[j] || dp[j - 1];
                }
            }
        }
        return dp[N2];
    }
};
