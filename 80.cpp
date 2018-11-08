 #include"iostream"
#include"cmath"
#include"cassert"
#include"ctime"
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) 
    {
        
        //其实，当前有多少个不重复的元素，那么下一个不重复的元素直接覆盖到这个索引位就可以了。 
		if (nums.size() == 0) 
        {
			return 0;
		}
        int j=0,sum=1;
        int tag=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[j]==nums[i])
            {
                tag++;
                if(tag<=3)
                {
                    sum++;
                    nums[sum-1]=nums[i];
                }
            }
            else
            {
                j=i;
                tag=1;
                sum++;
                nums[sum-1]=nums[i];
            }
        }
        return sum;
    }
int main()
{
	int  v1[10] = {0,1,1,1,1,2,2,3,3,4};
	vector<int> nums;
	for(int i=0;i<10;i++)
		nums.push_back(v1[i]);
	int po=0;	
	po=removeDuplicates(nums);
	printf("%d\n",po);
	for(int i=0;i<nums.size();i++)
		printf("%d ",nums[i]); 
	return 0;
}   
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
