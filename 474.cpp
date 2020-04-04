class Solution 
{
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int S = strs.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for(int l = 0; l < S; ++l) 
        {
            int zero = 0;
            int one = 0;
            for(int i = 0; i < strs[l].size(); ++i) 
            {
                if(strs[l][i] == '0') 
                    ++zero;
                else 
                    ++one;
            }
            for(int i = m; i >= zero; --i) 
            {
                for(int j = n; j >= one; --j) 
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zero][j - one]);
                }
            }
        }
        return dp[m][n];
    }
};
