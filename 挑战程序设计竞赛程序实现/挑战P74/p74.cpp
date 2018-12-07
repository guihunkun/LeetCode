#include"iostream"
#include"queue"
#include"cstdio"
using namespace std;
int main()
{
	int a[10]={12,34,3,8,5,45,288,12,35,10000};
	priority_queue<int> pque;
	pque.push(3);
	pque.push(5);
	pque.push(1);
	for(int i=0;i<10;i++)
		pque.push(a[i]);
	while(!pque.empty())
	{
		printf("%d\n",pque.top());
		pque.pop();
	}
	return 0;
}