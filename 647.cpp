/*
class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int res = 0;
        int N = 2*s.size()+1;
        for(int center = 0; center < N; center++)
        {
            int left = center/2;
            int right = left + center%2;
            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                res++;
                left--;
                right++;
            }
        }
        return res;
    }
};
*/

class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int res = s.size();
        int N = s.size();
        vector<vector<bool> > dp(N, vector<bool>(N, true));
        for(int i = 0; i < N; i++)
        {
            dp[i][i] = true;
        }
        for(int i = N-1; i >= 0; i--)
        {
            for(int j = i + 1; j < N; j++)
            {
                if(s[i] == s[j])
                {
                    if(j - i == 1)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                else
                {
                    dp[i][j] = false;
                }
                if(dp[i][j])
                {
                    res++;
                }
            }
        }
        return res;
    }
};
