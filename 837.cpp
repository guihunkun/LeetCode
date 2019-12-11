class Solution 
{
public:
    double new21Game(int N, int K, int W) 
    {
        if(K==0) return 1;
        double preWSum=1.0;
        vector<double> dp(N+1,0); //dp[i]表示点数为i的概率，每个dp[i]都由前W个dp转移过来
        dp[0]=1.0; //初始条件是0，所以一开始0的概率是1
        for(int i=1;i<=N;i++)
        {
            dp[i]=preWSum/W; //表示前W个dp之和
            if(i<K) preWSum+=dp[i]; // 当i大于等于K时，dp[i]不能转移
            if(i-W>=0&&i-W<K) preWSum-=dp[i-W];
        }
        double result=0.0;
        for(int i=K;i<=N;i++) result+=dp[i];
        return result;
    }
};
