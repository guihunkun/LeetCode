#include"iostream"
#include"queue"
#include"cstdio"
#include"vector"
using namespace std;
typedef long ll;
int N,L[20000];
class cmp
{
public:
    bool operator()(int a,int b)const
    {
        return a>b;
    }
};
void solve()
{
	ll ans=0;
	priority_queue<int,vector<int>,cmp>que;
	for(int i=0;i<N;i++)
	{
		que.push(L[i]);
	}
	while(que.size()>1)
	{
		int l1,l2;
		l1=que.top();
		que.pop();
		l2=que.top();
		que.pop();				
		ans+=l1+l2;
		que.push(l1+l2);
	}
	printf("%lld",ans);
}
int main()
{
	scanf("%d",&N);
	for(int j=0;j<N;j++)
		scanf("%d",&L[j]);
	solve();
	return 0;
}
