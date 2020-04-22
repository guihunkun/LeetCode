class Solution 
{
public:
    int longestPalindromeSubseq(string s) 
    {
        int N = s.size();
        vector<int> dp(N, 1);
        for(int i = N - 1; i >= 0; --i) 
        {
            int prev = 0;
            for(int j = i + 1; j < N; ++j) 
            {
                int temp = dp[j];
                if(s[i] == s[j]) 
                {
                    dp[j] = 2 + prev;
                } 
                else 
                {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }
        return dp[N - 1];
    }
};
