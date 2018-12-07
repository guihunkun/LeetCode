#include<iostream>
#include"string"
#include"fstream"
using namespace std;
int L[100],n[100],m;
int x[100][1000000];
int minn[100],maxx[100];
int max(int x,int y)
{
	if (x<=y)
		return y;
	else 
		return x;
}
int min(int x,int y)
{
	if (x<=y)
		return x;
	else 
		return y;
}

void solve(int mm) 
{
	int ll;
	ll=mm;
	int mint=0;
	for (int i=0;i<n[ll];i++)
	{
		mint=max(mint,min(x[ll][i],L[ll]-x[ll][i]));
	}
	int maxt=0;
	for (int ii=0;ii<n[ll];ii++)
	{
		maxt=max(maxt,max(x[ll][ii],L[ll]-x[ll][ii]));
	}
	minn[ll]=mint;
	maxx[ll]=maxt;
}

int main()
{
	int j=0;
	int jj=0;
	scanf("%d",&m);
	for (j=0;j<m;j++)
	{
		scanf("%d %d",&L[j],&n[j]);
		for (jj=0;jj<n[j];jj++)
		{
			scanf("%d",&x[j][jj]);
		}
	}
	for (int i=0;i<m;i++)
	{
		solve(i);
	}
	for(int ij=0;ij<m;ij++)
	{
		printf("%d %d\n",minn[ij],maxx[ij]);
	}
	return 0;
}


