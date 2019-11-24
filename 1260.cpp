class Solution 
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        vector<vector<int> > res(grid.size(), vector<int>(grid[0].size()));
        int n,m,t;
        n = grid.size();
        m = grid[0].size();
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                t = j + k;
                res[(i + t/m)%n][t % m] = grid[i][j];
            }
        }
        return res;
    }
};
