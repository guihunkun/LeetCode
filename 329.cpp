class Solution 
{
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        if(matrix.size() == 0) 
            return 0;
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int> > m(r, vector<int>(c, 0));
        int count = 1;
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                if(!m[i][j]) 
                    count = max(count, dfs(matrix, m, i, j));
        return count;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& m, const int i, const int j) 
    {
        if(m[i][j]) 
            return m[i][j];
        int r = matrix.size(), c = matrix[0].size();
        if(i > 0 && matrix[i-1][j] > matrix[i][j]) 
            m[i][j] = max(m[i][j], dfs(matrix, m, i-1, j));
        if(i < r-1 && matrix[i+1][j] > matrix[i][j]) 
            m[i][j] = max(m[i][j], dfs(matrix, m, i+1, j));
        if(j > 0 && matrix[i][j-1] > matrix[i][j]) 
            m[i][j] = max(m[i][j], dfs(matrix, m, i, j-1));
        if(j < c-1 && matrix[i][j+1] > matrix[i][j]) 
            m[i][j] = max(m[i][j], dfs(matrix, m, i, j+1));
        return ++m[i][j];
    }
};
