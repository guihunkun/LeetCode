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
 
//�ȽϹ�����С����
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
    int n;  //��Ҫ�и��ľ�����
    while(cin>>n)
    {
        priority_queue<__int64,vector<__int64>,cmp>Queue;  //�������ȶ���
 
        for(int i=1;i<=n;i++)
        {
            __int64 temp;
            scanf("%I64d",&temp);
            Queue.push(temp);       //����Ҫ���ľ�峤�ȣ����ã������
        }
 
        __int64 mincost=0;   //��С����
        while(Queue.size()>1)  //��������С�ڵ���һ��Ԫ��ʱ����
        {
            __int64 a=Queue.top();  //�õ�����Ԫ�ص�ֵ����ʹ�����
            Queue.pop();
            __int64 b=Queue.top();  //����ȡ���ף����õ���С������ֵ
            Queue.pop();
 
            Queue.push(a+b);  //���
            mincost+=a+b;
        }
 
        printf("%I64d\n",mincost);
 
        while(!Queue.empty())  //��ն���
            Queue.pop();
    }
    return 0;
}
