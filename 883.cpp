class Solution
{
public:
    int projectionArea(vector<vector<int>>& grid) 
    {
        int res = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            int maxrow = 0;
            int maxcol = 0;
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] > 0)
                    res++;
                maxrow = max(maxrow, grid[i][j]);
                maxcol = max(maxcol, grid[j][i]);
            }
            res += maxrow + maxcol;
        }
        return res;
    }
};
