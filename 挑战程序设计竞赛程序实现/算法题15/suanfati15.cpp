#include"iostream"
#include"string"
using namespace std;
char str[31];
int k;
void solve()
{
	k=0;
	for(int j=0;j<=31-3;j++)
	{
		if(((int(str[j])+int(str[j+1])+int(str[j+2]))==(65+66+67))&&(int(str[j])-int(str[j+1])))
			k++;
	}
	printf("%d\n",k);
}
int main()
{
	scanf("%s",&str);
	printf("%s\n",str);
	solve();
	return 0;
}