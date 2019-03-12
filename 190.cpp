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
ͨ��n & 1�õ�n�����һλ��Ȼ��n������һλ������һ��n & 1�����ǵõ�ԭ��n�ĵڶ�λ����
������µı����������ƣ���ô���԰�ԭ���±��������һλ�����ڶ�λ�� ����λ����һֱ�����λ��
*/
int main()
{
	unsigned n=00000010100101000001111010011100;
	unsigned gh=Solution().reverseBits(n);
	cout<<gh<<endl;
	return 0;
}
