#include<iostream>
#include"string"
#include"fstream"
using namespace std;
/*      全局变量      */
int n=5;
int a[5]={4,2,3,1,5};
int dp[1000];
/*      问题求解函数      */
int max(int mm,int nn)
{
	if(mm>nn)
		return mm;
	else
		return nn;
}
void solve() 
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
			if(a[j]<a[i])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		res=max(res,dp[i]);
	}
	printf("%d\n",res);
}
void main()
{	
	solve();
}

