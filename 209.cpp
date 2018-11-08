#include"iostream" 
#include"vector"
#include<string>
using namespace std;
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int l=0,r=-1;  //nums[l,..,r]Ϊ��������
        int res=nums.size()+1;
        int sum=0;
        while(l<nums.size())
        {
            if(r<int(nums.size()-1)&&(sum<s))
/* 
vector �е� size() ���ص��� size_type �ͣ����޷��ŵ�

��� size �� 0���� 1 �������ɺܴ��һ������r һ��С�������

��� -1 �� +1 ʵ���൱�������������������������ˣ��򲻳���

�� size() ���Ӽ���ʱ�������Ƚ� size() �ķ���ֵǿתΪ int
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
