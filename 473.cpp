class Solution 
{
public:
    bool makesquare(vector<int>& nums) 
    {   
        if(nums.empty()||nums.size()<4) 
            return false;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 4 != 0) 
            return false;
        vector<int> sums(4,0);  //长度为4的数组sums来保存每个边的长度和
        sort(nums.begin(),nums.end());
        return helper(nums,sums,0,sum/4);
    }
    bool helper(vector<int>& nums,vector<int>& sums,int pos,int target)
    {
        if(pos >= nums.size())
        {
            return sums[0] == target && sums[1] == target && sums[2] == target && sums[3] == target;
        }
        //对于当前这个火柴，尝试拼入上下左右四个边
        for(int i=0;i<4;++i)
        {
            if(sums[i]+nums[pos] > target) 
                continue;
            sums[i] += nums[pos]; //把当前火柴从i个边中拿出来，好尝试下一条边
            if(helper(nums,sums,pos+1,target)) 
                return true;  //如果这个火柴被成功使用，就开始尝试拼下一根火柴
            sums[i] -= nums[pos];  //用当前火柴拼第i个边
        }
        return false;
    }
};
