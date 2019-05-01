#include"iostream"
#include"vector"
#include"cmath"
using namespace std;
class Solution 
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            int val=abs(nums[i])-1;
            if(nums[val]>0)
                nums[val]=-nums[val];
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0)
                res.push_back(i+1);
        return res;
    }
};
/*
由于题目中有数组中所有数字都大于等于1且小于等于n，而n为数组长度这一条件。
所以可以以数组下标作为索引标记哪些数字出现过，标记方法为将出现数字对应下标的数字标为负数。

计算出数组中出现的数字x的下标形式，则下表为index = |x| - 1，可将数组a中得a[index]标为负数来标记数字x出现在数组中
若数组中某数字已为负数，说明该数字在数组中出现过
最终遍历数组，若a[i]为正数，表明数字 i + 1在数组中没有出现过。
*/
int main()
{
	int a[]={4,3,2,7,8,2,3,1};
	vector<int> nums;
	for(int i = 0; i < 8; i++)
		nums.push_back(a[i]);
	vector<int> res;
	res = Solution().findDisappearedNumbers(nums);
	for(int i = 0; i < res.size(); i++)
		cout<<res[i]<<" "  ;
	return 0;
}
