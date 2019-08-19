class Solution 
{
public:
    int getMoneyAmount(int n) 
    {
        vector<vector<int> >dp(n+1, vector<int>(n+1, 0));
        vector<int> a;
        for (int i = 0; i < n; ++i)
            a.push_back(i+1);
        for (int i = 0; i < n-1; ++i)
           dp[2][i]=a[i];
        for (int len = 3; len <= n; ++len) 
        {
            //开始求dp[3][i]
            for (int i = 0; i <= n-len; ++i) 
            {
        //对于每个dp[3][i]都要遍历每个值，进行且分，找到且分点的cost最小的值为dp[3][i]的值
                int global=0;
                for (int j = 0; j < len; ++j) 
                {
//对于每次切分之后的两个部分，取最大值,j是长度，从下标偏移位置为j的地方切分，左边长度为j，右边长度为len-j-1
                    //左边开始的值为i,右边开始的值为j+i+1,切分点为j+i
                    int tmp = max(dp[j][i], dp[len-j-1][j+i+1])+a[j+i];
                    //部分最大，整体最小
                    if(j==0) global = tmp;
                    else global = min(global, tmp);
                }
                dp[len][i] = global;
            }
        }
        return dp[n][0];
    }
};
