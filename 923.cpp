class Solution {
public:
    int mod = 1e9 + 7;
    int threeSumMulti(vector<int>& A, int target) {
        //dp[i][j][k]��ʾ����ǰi����ʱ������ѡ��j���������k��С�ķ�����
        int n = A.size();
        int dp[n + 1][4][target + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i ++ ) dp[i][0][0] = 1;
        //����Ҫ��1��ʼ����Ϊǰ0�����ǳ�ʼ������
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= 3; j ++ )
                for (int k = 0; k <= target; k ++ )
                {
                    //������A[i - 1]����Ϊ��1��ʼö���±꣬����A������˵��Ҫ��0��ʼ����˴��һ��
                    if (k >= A[i - 1]) dp[i][j][k] =(dp[i][j][k] + dp[i - 1][j - 1][k - A[i - 1]]) % mod;
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k]) % mod;
                }
        
        //���մ𰸾��ǿ���ǰn����ʱ��ѡ������3���������target��С�ķ�����
        return dp[n][3][target];
    }
};

