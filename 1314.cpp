class Solution 
{
public:
    int get(const vector<vector<int>>& pre, int m, int n, int x, int y) 
    {
        x = max(min(x, m), 0);
        y = max(min(y, n), 0);
        return pre[x][y];
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) 
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> P(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = get(P, m, n, i + K + 1, j + K + 1) - get(P, m, n, i - K, j + K + 1) - get(P, m, n, i + K + 1, j - K) + get(P, m, n, i - K, j - K);
            }
        }
        return ans;
    }
};
