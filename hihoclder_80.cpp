/*

СHi���ֻ���Ļ����0-9ʮ�����֣������·�ʽ���У�

1 2 3
4 5 6
7 8 9
  0
ÿ��СHi����һ������֮����һ����������ֻ��������������4����������֮һ��

����123�ǺϷ������룬��122��124�����ǺϷ��ġ�  

�������Ϸ���Nλ����һ���ж��ٸ��� ���ڽ�����ܷǳ�����ֻ��Ҫ����������1000000007��������  

ע���һλ������0-9������һλ��

����
һ������N��  

1 �� N �� 100000

���
һ��������ʾ�𰸡�







*/ 
#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll dp[10][maxn];
//dp[i][j]����Ϊj,��i��β������.
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=9;i++)
        dp[i][1]=1;
 
    for(int i=2;i<=n;i++)
    {
        dp[0][i]=(dp[0][i]+dp[8][i-1])%mod;
        dp[1][i]=(dp[1][i]+dp[2][i-1]+dp[4][i-1])%mod;
        dp[2][i]=(dp[2][i]+dp[1][i-1]+dp[3][i-1]+dp[5][i-1])%mod;
        dp[3][i]=(dp[3][i]+dp[2][i-1]+dp[6][i-1])%mod;
        dp[4][i]=(dp[4][i]+dp[1][i-1]+dp[5][i-1]+dp[7][i-1])%mod;
        dp[5][i]=(dp[5][i]+dp[2][i-1]+dp[4][i-1]+dp[6][i-1]+dp[8][i-1])%mod;
        dp[6][i]=(dp[6][i]+dp[3][i-1]+dp[5][i-1]+dp[9][i-1])%mod;
        dp[7][i]=(dp[7][i]+dp[4][i-1]+dp[8][i-1])%mod;
        dp[8][i]=(dp[8][i]+dp[5][i-1]+dp[7][i-1]+dp[9][i-1]+dp[0][i-1])%mod;
        dp[9][i]=(dp[9][i]+dp[6][i-1]+dp[8][i-1])%mod;
    }
    ll ans=0;
    for(int i=0;i<=9;i++)
        ans=(ans+dp[i][n])%mod;
    cout<<ans<<endl;
    return 0;
}

