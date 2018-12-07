/*#include"iostream"
#include"algorithm"  
#include"vector"  
#include"iterator" 
using namespace std;
int N,L[10000];
void solve()
{
	int ans=0;
	while(N>1)
	{
		int mii1=0,mii2=1;
		if(L[mii1]>L[mii2])
		{
			int mm=mii1;
			mii1=mii2;
			mii2=mm;
		}//swap(mii1,mii2);
		for(int i=2;i<N;i++)
		{
			if(L[i]<L[mii1])
			{
				mii2=mii1;
				mii1=i;
			}
			else if(L[i]<L[mii2])
			{
				mii2=i;
			}
		}
		int t=L[mii1]+L[mii2];
		ans+=t;
		if(mii1==N-1)
		{
			int nn=mii1;
			mii1=mii2;
			mii2=nn;
		}//swap(mii1,mii2);
		L[mii1]=t;
		L[mii2]=L[N-1];
		N--;
	}
	printf("%d",ans);
}
int main()
{
	scanf("%d",&N);
	for(int ii=0;ii<N;ii++)
		scanf("%d",&L[ii]);
	solve();
	return 0;
}
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
//比较规则，最小优先
class cmp
{
public:
    bool operator()(const __int64 a,const __int64 b)const
    {
        return a>b;
    }
};
 
int main(void)
{
    int n;  //需要切割的木板个数
    while(cin>>n)
    {
        priority_queue<__int64,vector<__int64>,cmp>Queue;  //定义优先队列
 
        for(int i=1;i<=n;i++)
        {
            __int64 temp;
            scanf("%I64d",&temp);
            Queue.push(temp);       //输入要求的木板长度（费用）并入队
        }
 
        __int64 mincost=0;   //最小费用
        while(Queue.size()>1)  //当队列中小于等于一个元素时跳出
        {
            __int64 a=Queue.top();  //得到队首元素的值，并使其出队
            Queue.pop();
            __int64 b=Queue.top();  //两次取队首，即得到最小的两个值
            Queue.pop();
 
            Queue.push(a+b);  //入队
            mincost+=a+b;
        }
 
        printf("%I64d\n",mincost);
 
        while(!Queue.empty())  //清空队列
            Queue.pop();
    }
    return 0;
}
