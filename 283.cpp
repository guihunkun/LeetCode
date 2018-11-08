#include"iostream"
#include"cmath"
#include"cassert"
#include"ctime"
#include<vector>
using namespace std;
    void moveZeroes(vector<int>& nums) 
    {
        int l=0, r=nums.size();
        int su=0;
        if(r==1)
            printf("%d",nums[0]);
        if(r>1)
        {
            for(int i=0;i<r;i++)
            {
                if(nums[i]==0)
                    su++;
                if(nums[i]!=0)
                    printf("%d",nums[i]);
            }
            for(int i=0;i<su;i++)
                printf("%d",0);
        }
    }
int main()
{
	vector<int> nums;
	nums.push_back(0);
	for(int i=1;i<7;i++)
		nums.push_back(i+1);
		
	moveZeroes(nums);
	return 0;
}
