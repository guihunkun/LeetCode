class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        int R = matrix.size();
        if(R == 0)
            return matrix;
        int C = matrix[0].size();
        vector<vector<int> > dist(R, vector<int>(C, INT_MAX));
        queue<pair<int,int> > q;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(matrix[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) 
        {
        pair<int, int> curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) 
        {
            int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
            if (new_r >= 0 && new_c >= 0 && new_r < R && new_c < C) 
            {
                if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) 
                {
                    dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                    q.push({ new_r, new_c });
                }
            }
        }
    }
    return dist;
    }
};