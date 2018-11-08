/*

小Hi的手机屏幕上有0-9十个数字，按如下方式排列：

1 2 3
4 5 6
7 8 9
  0
每当小Hi输入一个数字之后，下一个输入数字只能是其上下左右4个相邻数字之一。

例如123是合法的输入，而122和124都不是合法的。  

请你计算合法的N位输入一共有多少个？ 由于结果可能非常大，你只需要输出结果除以1000000007的余数。  

注意第一位可以是0-9中任意一位。

输入
一个整数N。  

1 ≤ N ≤ 100000

输出
一个整数表示答案。







*/ 
#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll dp[10][maxn];
//dp[i][j]长度为j,以i结尾的数字.
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

