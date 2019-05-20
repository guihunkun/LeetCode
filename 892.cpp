class Solution
{
public:
    int surfaceArea(vector<vector<int>>& grid) 
    {
        int area = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) 
            {
                if (grid[i][j] > 0)
                    area += 4 * grid[i][j] + 2;
                if (i < grid.size() - 1)
                    area -= min(grid[i][j], grid[i + 1][j]) * 2;
                if (j < grid[0].size() - 1)
                    area -= min(grid[i][j], grid[i][j + 1]) * 2;
            }
        return area;
    }
};
/*
每一个格子上的形体的表面积是四周的表面积是4 * h +上底下底面积是2 若有相邻的形体，
则会有一个面接触，也就是表面积会少了2 * min(这两个形体高度)。
*/
