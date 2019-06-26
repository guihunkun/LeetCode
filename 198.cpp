class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int> memo(n,-1);
        //memo[i]表示抢劫nume[0,....i]所能获得的最大收益
        memo[0]=nums[0];
        for(int i=1;i<n;i++)
            for(int j=i;j>=0;j--)
                memo[i]=max(memo[i],nums[j]+(j-2 >= 0 ? memo[j-2]:0));
        return memo[n-1];
    }
};
/*
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int> memo(n,-1);
        //memo[i]表示抢劫nume[i,....n-1]所能获得的最大收益
        memo[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            for(int j=i;j<n;j++)
                memo[i]=max(memo[i],nums[j]+(j+2 <n ? memo[j+2]:0));
        return memo[0];
    }
};
*/
