class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int> memo(n,-1);
        //memo[i]��ʾ����nume[0,....i]���ܻ�õ��������
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
        //memo[i]��ʾ����nume[i,....n-1]���ܻ�õ��������
        memo[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            for(int j=i;j<n;j++)
                memo[i]=max(memo[i],nums[j]+(j+2 <n ? memo[j+2]:0));
        return memo[0];
    }
};
*/
