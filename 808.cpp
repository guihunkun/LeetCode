class Solution 
{
public:
    int M(int x)
    {
        return max(x,0);
    }
    double soupServings(int N) 
    {
        N = N/25 + (N%25 > 0 ? 1 : 0);
        if(N >= 500)
            return 1.0;
        vector<vector<double> > memo(N+1, vector<double>(N+1));
        for (int s = 0; s <= 2*N; ++s) 
        {
            for (int i = 0; i <= N; ++i) 
            {
                int j = s-i;
                if (j < 0 || j > N) 
                    continue;
                double ans = 0.0;
                if (i == 0) 
                    ans = 1.0;
                if (i == 0 && j == 0) 
                    ans = 0.5;
                if (i > 0 && j > 0) 
                {
                    ans = 0.25 * (memo[M(i-4)][j] + memo[M(i-3)][M(j-1)] +
                                  memo[M(i-2)][M(j-2)] + memo[M(i-1)][M(j-3)]);
                }
                memo[i][j] = ans;

            }
        }
        return memo[N][N];
    }
};
