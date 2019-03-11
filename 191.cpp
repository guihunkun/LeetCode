#include"iostream"
using namespace std;
    int hammingWeight(unsigned n)
    {
        int count=0;
        for(int i=0;i<32;i++)
        {
            if((n%2)!=0)
                count++;
            n>>=1;
        }
        return count;
    }
int main()
{
	unsigned n=00000000000000000000000000001011;
	int res=0;
	res=hammingWeight(n);
	cout<<res<<endl;
}
