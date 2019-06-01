class Solution 
{
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        if(grid.size()==0) 
            return 0;
        int cnt = 0, repeat = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(!grid[i][j]) 
                    continue;
                cnt++;
                if(i!=0 && grid[i-1][j]) 
                    repeat++;
                if(j!=0 && grid[i][j-1]) 
                    repeat++;
            }
        }
        return cnt * 4 - repeat * 2;
    }
};
/*
只需要计算为1的方格数量和重复的边数即可。为防止重复计算重合边, 
每次只往回查看, 也就是如果一个方格为1, 只查看左边和上边的方格是否为1.
*/
