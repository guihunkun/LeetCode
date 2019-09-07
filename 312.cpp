class Solution 
{
public:
    int maxCoins(vector<int>& nums) 
    {
        int arr[nums.size()+2];
        for(int i=1;i<nums.size()+1;++i)arr[i] = nums[i-1];
        arr[0] = arr[nums.size()+1] = 1;
        
        int dp[nums.size()+2][nums.size()+2]={};
        int n = nums.size()+2;
        
        for(int k=1;k<n;++k)
        {
            for(int left = 0;left<n-k;++left)
            {
                int right = left + k;
                for(int i=left+1;i< right; ++i)
                {
                    dp[left][right] = max(dp[left][right],arr[left]*arr[i]*arr[right] + dp[left][i] + dp[i][right]);
                }
            }    
        }
        return dp[0][n-1];
    }
};
