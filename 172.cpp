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

/*要求末尾有多少个零，则该数应为x*10^k 的形式等于x*（2^k *5^k）
也就是求该数分解质因子后有几个5就行，：如1*2*3*4*5=1*2*3*2*2*5（里面有一个5）所以结果为1个0
*/
int main()
{
	int n=5;
	int res=Solution().trailingZeroes(n);
	cout<<res<<endl;
	return 0;
}

