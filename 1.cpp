#include"iostream"
#include"vector"
#include"map"
using namespace std;
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
       
        vector<int> ans;
        map<int,int> record;
        for(int i=0;i<nums.size();i++)
            record[nums[i]]=i;
        for(int i=0;i<nums.size();i++)
        {
            if(record.count(target-nums[i]) && record[target-nums[i]]!=i)
            {
                ans.push_back(i);
                ans.push_back(record[target-nums[i]]);
                break;
            }
        }
        return ans;
    }
};

int main() 
{
	int target=target = 9;
	int lis[]={2, 7, 11, 15};
	vector<int> nums,ans;
	for(int i=0;i<4;i++)
		nums.push_back(lis[i]);
	ans=Solution().twoSum(nums,target);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}
