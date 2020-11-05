class Solution 
{
public:
    int minFallingPathSum(vector<vector<int> >& A)
    {
        /*
        * dp(r,c) : 从第r层，第c列开始的最小路径和。
        * 当r为最后一层时，dp(r,c) = A[r][c];
        * 当r不为最后一层时，dp(r,c) = A[r][c] + 下一层的子问题的解的最小值。
        * 状态转移方程 (在不考虑边界的情况下)
        * dp(r,c) = A[r][c] + min(dp[r+1][c-1], dp[r+1][c], dp[r+1][c+1])
        */
        int row = A.size();
        int col = A[0].size();
        for(int r = row-2; r >= 0; r--)
        {
            for(int c = 0; c < col; c++)
            {
                // best = min(A[r+1][c-1], A[r+1][c], A[r+1][c+1])
                int best = A[r+1][c];
                if(c > 0)
                    best = min(best, A[r+1][c-1]);
                if(c+1 < col)
                    best = min(best, A[r+1][c+1]);
                A[r][c] += best;
            }
        }
        int res = INT_MAX;
        for(auto x : A[0])
            res = min(res, x);
        return res;

    }
};
