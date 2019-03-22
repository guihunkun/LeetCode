#include"iostream"
#include"vector"
using namespace std; 
/*
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int psum=nums[0];
        int maxsum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            psum=psum>0?psum+nums[i]:nums[i];
            maxsum=max(maxsum,psum);
        }
        return maxsum;
    }
};
*/

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        return maxSubSumRec(nums, 0, nums.size()-1);
    }
    int maxSubSumRec(vector<int>& nums, int left, int right)
    {
        if(left>=right)
            return nums[left];
        int center=left+(right-left)/2;
        int lmax=maxSubSumRec(nums,left,center-1);
        int rmax=maxSubSumRec(nums,center+1,right);
        int mmax=nums[center],t=mmax;
        int i;
        
        for(i=center-1;i>=left;i--)
        {
            t+=nums[i];
            mmax=max(t,mmax);
        }
        t=mmax;
        for(i=center+1;i<=right;i++)
        {
            t+=nums[i];
            mmax=max(t,mmax);
        }
        return max(mmax, max(lmax, rmax));
    }
};
int main()
{
	int a[]={-2,1,-3,4,-1,2,1,-5,4};
	vector<int> nums;
	for(int i=0;i<9;i++)
		nums.push_back(a[i]);
	Solution sol;
	int ans=sol.maxSubArray(nums);
	cout<<ans<<endl;
	return 0;
}

