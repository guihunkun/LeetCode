class Solution 
{
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int n,m;
        n = grid.size();
        if(n == 0)
            return 0;
        m = grid[0].size();
        int ans = 0;
        vector<int> row(n), column(m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                    continue;
                row[i]++;
                column[j]++;
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                    continue;
                if(row[i] == 1 && column[j] == 1)
                    continue;
                ans++;
            }
        }
        return ans;
    }
};
