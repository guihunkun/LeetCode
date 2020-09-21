class Solution 
{
public:
    vector<vector<int> > dirs = {{-1,-1}, {-1,1}, {-1,0}, {0,1}, {0,-1}, {1,-1}, {1,1}, {1,0}};
    void dfs(vector<vector<int> >& land, int x, int y, int& count)
    {
        land[x][y] = -1; //染色
        count++;
        for(int i = 0; i < dirs.size(); i++)
        {
            int dx = x + dirs[i][0];
            int dy = y + dirs[i][1];
            if(dx >= 0 && dx < land.size() && dy >= 0 && dy < land[0].size() && land[dx][dy] == 0)
            {
                dfs(land, dx, dy, count);
            }
        }

    }
    vector<int> pondSizes(vector<vector<int>>& land) 
    {
        vector<int> res;
        if(land.empty())
        {
            return res;
        }
        for(int i = 0; i < land.size(); i++)
        {
            for(int j = 0; j < land[i].size(); j++)
            {
                int count = 0;
                if(land[i][j] == 0)
                {
                    dfs(land, i,j,count);//有效的一次dfs
                    if(count != 0)//计算一片鱼塘大小
                        res.push_back(count);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
