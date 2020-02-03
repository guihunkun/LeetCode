class Solution 
{
public:
    vector<vector<int> > generateMatrix(int n) 
    {
        vector<vector<int> > ans;
        vector<int> tmp;
        int x, y, dir;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for(x = 0; x < n; x ++)
            tmp.push_back(0);
        for(x = 0; x < n; x ++)
            ans.push_back(tmp);
        x = 0, y = 0, dir = 0;
        ans[0][0] = 1;
        for(int i = 2; i <= n * n; i ++)
        {
            if(x + dx[dir] < 0 || x + dx[dir] >= n || y + dy[dir] < 0 || y + dy[dir] >= n )
                dir = (dir + 1) % 4;
            else if(ans[x + dx[dir]][y + dy[dir]] > 0)
                dir = (dir + 1) % 4;
            x += dx[dir], y += dy[dir];
            ans[x][y] = i;
        }
        return ans;
    }
};
