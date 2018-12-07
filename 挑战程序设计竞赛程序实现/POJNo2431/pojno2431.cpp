#include"iostream"
#include"queue"
#include"cstdio"
using namespace std;
int L,N,P;
int A[10001],B[10001];
void solve()
{
	A[N]=L;
	B[N]=0;
	N++;
	priority_queue<int> que;
	int ans=0,pos=0,tank=P;  //ans:加油数  pos:现在所在位置  tank:油箱中汽油的量
	for(int i=0;i<N;i++)
	{
		int d=A[i]-pos;
		while(tank-d<0)
		{
			if(que.empty())
			{
				printf("%d",-1);
				return;
			}
			tank+=que.top();
			que.pop ();
			ans++;
		}
		tank-=d;
		pos=A[i];
		que.push(B[i]);		
	}
	printf("%d",ans);
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d\n",&A[i],&B[i]);
	}
	scanf("%d %d",&L,&P);
	solve();
	return 0;
}