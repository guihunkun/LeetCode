#include"iostream"
#include <bitset>
using namespace std;

class Solution 
{
public:
    int findComplement(int num) 
    {
        int res=0;
        int step=0;
        while(num>0)
        {
            if((num & 0x1)==0x0)
                res+=1<<step;
            num=num>>1;
            step++;
        }
        return res;
    }
};

int main()
{
	int gh=0x1<<3;
	cout<<bitset<32>(gh)<<endl;//输出二进制数
	return 0;
}




