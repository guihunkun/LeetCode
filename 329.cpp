class Solution 
{
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& length,int x,int y,int n,int m) 
    {
        if (length[x][y]>0)
            return length[x][y];
        int max_len=0;
        for (int i=0;i<4;++i) 
        {
            int nx=dir[i][0]+x;
            int ny=dir[i][1]+y;
            if (nx<0 || nx>=n || ny<0 || ny>=m || matrix[nx][ny]<=matrix[x][y])
                continue;
            int cc = dfs(matrix,length,nx,ny,n,m);
            max_len = max(max_len,cc);
        }
        length[x][y] = max_len+1;
        return max_len+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> length(n,vector<int>(m,0));
        int max_length=0;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j) 
            {
                int len=dfs(matrix,length,i,j,n,m);
                if (len>max_length)
                    max_length=len;
            }
        return max_length;
    }
};
/*
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
*/
