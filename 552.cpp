class Solution 
{
public:
    int mod=1e9+7;
    int dp[100001][2][3];
    int checkRecord(int n)
    {
        memset(dp,-1,sizeof(int)*100001*2*3);
        return dfs(0,0,0,n);
    }
    int dfs(int i,int a,int l,int n)
    {
        if(dp[i][a][l]!=-1) 
            return dp[i][a][l];
        if(i==n) 
            return 1;
        int ans=0;
        if(a==0) 
            ans=(ans+dfs(i+1,1,0,n))%mod;
        if(l==2) 
            ans=(ans+dfs(i+1,a,0,n))%mod;
        else
        {
            ans=(ans+dfs(i+1,a,l+1,n))%mod;
            ans=(ans+dfs(i+1,a,0,n))%mod;
        }
        dp[i][a][l]=ans;
        return ans;
    }
};
