#include"iostream" 
#include<string>
#include"vector"
using namespace std;
//由于所有数都是整数，所以最大位数为32位，对于出现三次的数，统计每一位上1出现的次数一定能被3整除，而不能被三整除的位一定是单独出现的数造成的，所以依次统计每一位的次数，并把不能被3整除的位数设为1赋给结果。
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
                result |= mask;  //按位或后赋值。如：a|=b等价于a=a|b
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
