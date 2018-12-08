#include"iostream"
#include"math.h"
#include"limits.h"
using namespace std;
int main()
{
	long long x=-3648;
	long long ret=0;
	int sign=(x>0)?1:-1;
	x=abs(x);
	while(x)
	{
		int digit=x%10;
		x/=10;
		ret=ret*10+digit;
	}
	ret*=sign;
	if(ret>INT_MAX||ret<INT_MIN)
		cout<<0;
	else 
		cout<<ret<<endl;
		//cout<<INT_MAX;
	return 0;
 } 
