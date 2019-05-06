#include"iostream"
#include"vector"
using namespace std;
class Solution 
{
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int count = 0, maxleft = nums[0];
        for(int i = 1; i < nums.size(); i ++)
        {
            if(nums[i] < maxleft)
            {
                count ++;
            }
            maxleft = max(nums[i], maxleft);
        }
        int count1 = 0, minright=nums[nums.size()-1];
        for(int i = nums.size()-2; i >= 0; i--)
        {
            if(nums[i] > minright)
                count1++;
            minright = min(minright, nums[i]);
        }
        return (count <=1 || count1 <= 1);
    }
};
int main()
{
	vector<int> nums;
	int a[4]={3,4,2,3};
	for(int i=0;i<4;i++)
		nums.push_back(a[i]);

//	int a[4]={4,2,3};
//	for(int i=0;i<3;i++)
//		nums.push_back(a[i]);

	cout<<Solution().checkPossibility(nums)<<endl;
	return 0;
} 
