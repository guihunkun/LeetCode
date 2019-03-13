#include"iostream"
#include"vector"
#include<stdlib.h>
using namespace std;

/*
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int n=nums.size();
        int res=nums[0];
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                res=nums[i];
                count=1;
            }
            else
            {
                if(res==nums[i])
                    count++;
                else
                    count--;
            }
        }
        return res;
    }
};
*/

class Solution 
{
public://随机挑选一个元素，检查是否是多数元素。时间复杂度：Average：O(n)。期望查找次数 <2
    int majorityElement(vector<int>& nums) 
    {
        int count = 0;
        for(;;) 
        {
            if(nums.size() == 1)
                return nums[0];
            else    
            {
                int i = rand() % (nums.size() - 1);
                for(int j = 0; j < nums.size(); j++) {
                    if(nums[j] == nums[i])
                        count++;
                }
                if(count > (nums.size() / 2))
                    return nums[i];
                else    
                {
                    count = 0;
                    continue;
                }
            }
        }
    }
};

int main()
{
	vector<int> nums;
	int li[3]={5,6,6};
	for(int i=0;i<3;i++)
		nums.push_back(li[i]);
	int ans=Solution().majorityElement(nums);
	cout<<ans<<endl;
	return 0;	
}
