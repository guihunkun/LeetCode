#include"iostream"
#include <bitset>
using namespace std;
class Solution 
{
public:
    unsigned reverseBits(unsigned n) 
    {
        unsigned res=0;
        for(int i=0;i<32;i++)
        {
            res=(res<<1)|(n&0x01);
            n>>=1;
        }
        return res;
    }
};
/*
通过n & 1得到n的最后一位，然后将n向右移一位，再来一次n & 1，于是得到原来n的第二位……
如果对新的变量进行左移，那么可以把原来新变量的最后一位移至第二位， 第三位……一直到最高位。
*/
int main()
{
	unsigned n=00000010100101000001111010011100;
	unsigned gh=Solution().reverseBits(n);
	cout<<gh<<endl;
	return 0;
}
