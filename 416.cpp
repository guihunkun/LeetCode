
class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            assert(nums[i]>=0);
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        int n=nums.size();
        int C=sum/2;
        vector<bool> memo(C+1,-1);
        for(int i=0;i<=C;i++)
            memo[i]=(nums[0]==i);
        for(int i=1;i<n;i++)
            for(int j=C;j>=nums[i];j--)
                memo[j]=memo[j]||memo[j-nums[i]];
        return memo[C];
        
    }
};


/*
class Solution 
{

private:
    vector<vector<int>> memo;
    //-1 表示未计算； 0表示无法填充； 1表示可以填充
    bool tryPartition(const vector<int>& nums,int index, int sum)
    {
        if(sum==0)
            return true;
        if(sum<0 || index<0)
            return false;
        if(memo[index][sum]!=-1)
            return memo[index][sum]==1;
        memo[index][sum]=(tryPartition(nums,index-1,sum) || tryPartition(nums,index-1,sum-nums[index]))?1:0;
        return memo[index][sum]==1;
    }
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            assert(nums[i]>=0);
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        memo=vector<vector<int>>(nums.size(),vector<int>(sum/2+1,-1));
        return tryPartition(nums,nums.size()-1,sum/2);
    }
};
*/
