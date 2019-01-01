/*
bpos表示从字符串是否可以从开头cut到当前位置。
bpos[i]==true代表从字符串开头到第i个字符结束，存在合理的cut。
在字符串s前面加上0，从而为动态规划设置初值即bpos[0]==true
*/
class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n=s.size();
        vector<bool> dp(n+1,false);
        unordered_set<string> ss;
        for(auto &s:wordDict) 
            ss.insert(s);
        dp[0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j>0;j--)
            {
                if(dp[j-1]==false) 
                    continue;
                if(ss.find(s.substr(j-1,i-j+1))!=ss.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
