class Solution 
{
public:
    bool isContinous(char prev, char curr) 
    {
        if(prev == 'z') 
            return curr == 'a';
        return prev + 1 == curr;
    }
    int findSubstringInWraproundString(string p) 
    {
        vector<int> dp(26, 0);
        int N = p.size();
        int k = 0;
        for(int i = 0; i < N; ++i) 
        {
            if(i > 0 && isContinous(p[i - 1], p[i])) 
            {
                ++k;
            } 
            else 
            {
                k = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
