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
ֻ��Ҫ����Ϊ1�ķ����������ظ��ı������ɡ�Ϊ��ֹ�ظ������غϱ�, 
ÿ��ֻ���ز鿴, Ҳ�������һ������Ϊ1, ֻ�鿴��ߺ��ϱߵķ����Ƿ�Ϊ1.
*/
