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
ÿһ�������ϵ�����ı���������ܵı������4 * h +�ϵ��µ������2 �������ڵ����壬
�����һ����Ӵ���Ҳ���Ǳ����������2 * min(����������߶�)��
*/
