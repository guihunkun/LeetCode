#include"iostream"
#include"vector"
//#include"assert.h"
using namespace std;

/*
class Solution 
{
public:
    
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        assert(k>=0);
        if(k==0 || k%n==0)
            return;
        k=k%n;
        int temp, previous;
        for (int i = 0; i < k; i++) 
        {
            previous = nums[nums.size() - 1];
            for (int j = 0; j < nums.size(); j++) 
            {
                temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }
    
};
*/
/*
class Solution 
{
public:
    
    void rotate(vector<int>& nums, int k) 
    {
        
        int n=nums.size();
        assert(k>=0);
        if(k==0 || k%n==0)
            return;
        k=k%n;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
            ans[(i+k)%n]=nums[i];
        for(int i=0;i<n;i++)
            nums[i]=ans[i];
    }
    
};
*/

    void reverse(vector<int>& nums,int left,int right)
    {
        while(left<right)
        {
        	int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            //swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        //assert(k>=0);
        if(k==0 || k%n==0)
            return;
        k=k%n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    } 


int main()
{
	vector<int> nums;
	int k=3;
	for(int i=0;i<7;i++)
		nums.push_back(i+1);
	rotate(nums,k);
	for(int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	return 0;
	
}


