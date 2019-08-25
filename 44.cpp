class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        int m=s.size(),n=p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;
        //dp[i][j] means s 0...i matchs p 0...j
        for(int i=0;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1] == '*')
                {
// =dp[i][j-1] 的意思是j没有用来匹配，i匹配不匹配取决于0...i和0...j-1匹配不匹配
// =dp[i-1][j-1] 意思是j用来和i匹配了(只使用一次，等同于？），看之前的0...i-1和0...j-1匹配不匹配
// =dp[i-1][j] 的意思是i被wildcard匹配了（j使用作为多个字符），看之前的0...i-1和0..j匹配不匹配
// 这里比较难理解的是为什么=dp[i-1][j], 0...i-1和0...j的原因是第j个位置可能被使用了很多次，从理解上看是j这个位置不变，i一直增加，也就是说j这个位置被用来匹配了很多个字符
                    dp[i][j] = dp[i][j-1] or (i>0 and (dp[i-1][j-1] or dp[i-1][j]));   
                }
                else
                {
                    if(i>0 and ((s[i-1]==p[j-1] ) or (p[j-1] == '?')) ) 
                        dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
