#include"iostream" 
#include<string>
#include"vector"
using namespace std;
//���������������������������λ��Ϊ32λ�����ڳ������ε�����ͳ��ÿһλ��1���ֵĴ���һ���ܱ�3�����������ܱ���������λһ���ǵ������ֵ�����ɵģ���������ͳ��ÿһλ�Ĵ��������Ѳ��ܱ�3������λ����Ϊ1���������
    int singleNumber(vector<int>& nums) 
    {
        int length = nums.size();
        int result = 0;
        for(int i = 0; i<32; i++){
            int count = 0; 
            int mask = 1 << i;
            cout<<mask<<endl;
            for(int j=0; j<length; j++){
                if(nums[j] & mask)
                    count++;
            }
          if(count %3)
                result |= mask;  //��λ���ֵ���磺a|=b�ȼ���a=a|b
        }
        return result;

    }
int main()
{
	int  v1[10] = {0,0,0,1,1,1,2,2,2,4};
	vector<int> nums;
	for(int i=1;i<10;i++)
		nums.push_back(v1[i]);
	int po=singleNumber(nums) ; 
	cout<<po<<endl;
	return 0;
}
