#include"iostream"
using namespace std;
class Solution
{
public:
    int trailingZeroes(int n) 
    {
        int res=0;
        while(n)
        {
            n/=5;
            res+=n;
        }
        return res;
    }
};
/*Ҫ��ĩβ�ж��ٸ��㣬�����ӦΪx*10^k ����ʽ����x*��2^k *5^k��
Ҳ����������ֽ������Ӻ��м���5���У�����1*2*3*4*5=1*2*3*2*2*5��������һ��5�����Խ��Ϊ1��0
*/
int main()
{
	int n=5;
	int res=Solution().trailingZeroes(n);
	cout<<res<<endl;
	return 0;
}
