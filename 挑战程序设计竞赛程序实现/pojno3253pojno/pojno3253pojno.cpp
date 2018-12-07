#include"iostream"
using namespace std;
int N,L[10000];
void pop()
{
	int LL[10000];
	int j=0;
	for(int i=0;i<N;i++)
		LL[i]=L[i+2];
	N=N-2;
	for(j=0;j<N;j++)
		L[j]=LL[j];
	for(int k=N;k<10000;k++)
		L[k]=0;
}
void top(int kk)
{
	int j=0;
	for(j=0;j<N;j++)
		if(L[j]>kk)
			break;
	for(int t=j;t<N;t++)
		L[t+1]=L[t];
	L[j]=kk;
	N=N+1;
}
int main()
{
	int key,i,k,su;
	int res=0;
	int j=0;
	k=0;
	su=0;
	key=0;
	i=0;
	scanf("%d",&N);
	for(int ii=0;ii<N;ii++)
		scanf("%d",&L[ii]);
	for(j=1;j<N;j++)
	{
		key=L[j];
		i=j-1;
		while((j>0)&&(L[i]>=key))
		{
			L[i+1]=L[i];
			i=i-1;
		}
		L[i+1]=key;
	}
	while(N>0)
	{
		su=L[0]+L[1];
		res+=su;
		pop();
		if(N==0)
			break;
		top(su);
		//k++;
	}
	printf("%d",res);
	return 0;
}

