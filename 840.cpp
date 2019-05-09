class Solution 
{
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        int R = grid.size(), C = grid[0].size();
        int ans = 0;
        for (int r = 0; r < R-2; ++r)
            for (int c = 0; c < C-2; ++c)
            {
                if (grid[r+1][c+1] != 5) 
                    continue;  // optional skip
                if (magic(grid[r][c], grid[r][c+1], grid[r][c+2],
                          grid[r+1][c], grid[r+1][c+1], grid[r+1][c+2],
                          grid[r+2][c], grid[r+2][c+1], grid[r+2][c+2]))
                    ans++;
            }
        return ans;
    }
    bool magic(int a11, int a12, int a13, int a21, int a22, int a23, int a31, int a32, int a33) 
    {
        vector<int> count(16);
        count[a11]++;count[a12]++;count[a13]++;
        count[a21]++;count[a22]++;count[a23]++;
        count[a31]++;count[a32]++;count[a33]++;
        for(int v = 1; v <= 9; v++)
            if(count[v] != 1)
                return false;
        return (a11 + a12 + a13 == 15 &&
                a21 + a22 + a23 == 15 &&
                a31 + a32 + a33 == 15 &&
                a11 + a21 + a31 == 15 &&
                a12 + a22 + a32 == 15 &&
                a13 + a23 + a33 == 15 &&
                a11 + a22 + a33 == 15 &&
                a31 + a22 + a13 == 15);
    }
};
