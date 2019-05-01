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
������Ŀ�����������������ֶ����ڵ���1��С�ڵ���n����nΪ���鳤����һ������
���Կ����������±���Ϊ���������Щ���ֳ��ֹ�����Ƿ���Ϊ���������ֶ�Ӧ�±�����ֱ�Ϊ������

����������г��ֵ�����x���±���ʽ�����±�Ϊindex = |x| - 1���ɽ�����a�е�a[index]��Ϊ�������������x������������
��������ĳ������Ϊ������˵���������������г��ֹ�
���ձ������飬��a[i]Ϊ�������������� i + 1��������û�г��ֹ���
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
