#include"iostream" 
#include"vector"
#include<string>
using namespace std;
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int l=0,r=-1;  //nums[l,..,r]为滑动窗口
        int res=nums.size()+1;
        int sum=0;
        while(l<nums.size())
        {
            if(r<int(nums.size()-1)&&(sum<s))
/* 
vector 中的 size() 返回的是 size_type 型，是无符号的

如果 size 是 0，减 1 后溢出变成很大的一个数，r 一定小于这个数

如果 -1 再 +1 实际相当于向下溢出后，再向上溢出回来了，则不出错

对 size() 作加减法时，可以先将 size() 的返回值强转为 int
*/

                sum+=nums[++r];
            else
                sum-=nums[l++];
            if(sum>=s)
                res=min(res,r-l+1);
        }
        if(res==nums.size()+1)
            return 0;
        return res;
    }
int main()
{
	int v1[] = {2,3,1,2,4,3};
	vector<int> nums;
	int s=7;
	int po;
	for(int i=0;i<6;i++)
		nums.push_back(v1[i]);
	po=minSubArrayLen(s,nums);
	cout<<po<<endl;
	return 0;
}
