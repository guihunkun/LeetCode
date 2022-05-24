class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        if(nums.size()==1)
            return nums[0];
        int left=0,right=nums.size()-1;
        int mid=left;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(nums[left] < nums[right]) 
	  	        return nums[left];
            if(nums[left]==nums[mid] && nums[mid]==nums[right])
            {
                return MinInOrder(nums,left,right);
            }   
            if(nums[left]<=nums[mid])
                left=mid+1;
            else if(nums[mid]<=nums[right])
                right=mid;
        }
        return nums[left];
    }
    int MinInOrder(vector<int> & nums,int left,int right)
    {
        int res=nums[left];
        for(int i=left+1;i<=right;i++)
            if(res>nums[i])
                res=nums[i];
        return res;
    }
};
