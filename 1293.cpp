struct Nagato 
{
    int x, y;
    int rest;
    Nagato(int _x, int _y, int _r): x(_x), y(_y), rest(_r) {}
};

class Solution 
{
public:
    vector<vector<int> > dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int shortestPath(vector<vector<int>>& grid, int k)
    {
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        if(m == 1 && n == 1) 
        {
            return 0;
        }
        k = min(k, m + n - 3);
        vector<vector<vector<bool> > > vis(m, vector<vector<bool> >(n, vector<bool>(k+1, false)));
        queue<Nagato> q;
        q.push(Nagato(0, 0, k));
        vis[0][0][k] = true;
        for(int step = 1; q.size() > 0; ++step) 
        {
            int cnt = q.size();
            for(int j = 0; j < cnt; ++j) 
            {
                Nagato cur = q.front();
                q.pop();
                for(int i = 0; i < dirs.size(); ++i) 
                {
                    int nx = cur.x + dirs[i][0];
                    int ny = cur.y + dirs[i][1];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n) 
                    {
                        if(grid[nx][ny] == 0 && !vis[nx][ny][cur.rest]) 
                        {
                            if(nx == m - 1 && ny == n - 1) 
                            {
                                return step;
                            }
                            q.push(Nagato(nx, ny, cur.rest));
                            vis[nx][ny][cur.rest] = true;
                        }
                        else if(grid[nx][ny] == 1 && cur.rest > 0 && !vis[nx][ny][cur.rest - 1]) 
                        {
                            q.push(Nagato(nx, ny, cur.rest - 1));
                            vis[nx][ny][cur.rest - 1] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
