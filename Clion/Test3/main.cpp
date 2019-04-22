
/*
#include"iostream"
#include"vector"
//#include"assert.h"
using namespace std;

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
*/
#include"iostream"
#include"vector"
using namespace std;
int main()
{
    vector<int> res{1,2,3};
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" "<<endl;

    cout<<"***************"<<endl;
    int ary[]={1,2,3,4,5};
    for(int & e : ary )
        e*=10;
    for(int e:ary)
        cout<<e<<" ";
    cout<<endl;
    cout<<"***************"<<endl;
    return 0;
}