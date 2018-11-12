#include"iostream"
#include"vector" 
using namespace std; 	
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int Gcd(vector<int> cn,int n)
{
 	int c=cn[0];
	for(int i=1;i<n;i++)
	{
		c=gcd(c,cn[i]);
	}
	return c;
}
int main()
{
 	int a,n;
 	vector<int> cn;
 	cout<<"请输入整数个数"<<endl;
	scanf("%d",&n);  
	cout<<"请输入n个整数"<<endl;
 	for(int i=0;i<n;i++)
 	{
 		cin>>a;
		cn.push_back(a);
	}
 	cout<<"他们的最大公约数是："<<endl;
 	cout<<Gcd(cn,n)<<endl;
//	int a,b;
//	scanf("%d %d",&a,&b);
//	cout<<gcd(a,b)<<endl;

	return 0;
}
