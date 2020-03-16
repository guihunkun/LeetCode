class Solution 
{
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    struct Cmp 
    {
        bool operator() (const vector<int>& v1, const vector<int>& v2) const 
        {
            return v1[2] > v2[2];
        }
    };
    bool valid(int r, int c, int R, int C) 
    {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        if(heightMap.empty()) 
            return 0;
        int R = heightMap.size();
        int C = heightMap[0].size();
        if(R < 3 || C < 3) 
            return 0;
        priority_queue<vector<int>, vector<vector<int> >, Cmp> q;
        for(int i = 0; i < R; ++i) 
        {
            q.push({i, 0, heightMap[i][0]});
            q.push({i, C - 1, heightMap[i][C - 1]});
            heightMap[i][0] = heightMap[i][C - 1] = -1;
        }
        for(int j = 1; j < C - 1; ++j) 
        {
            q.push({0, j, heightMap[0][j]});
            q.push({R - 1, j, heightMap[R - 1][j]});
            heightMap[0][j] = heightMap[R - 1][j] = -1;
        }
        int res = 0;
        while(!q.empty()) 
        {
            auto t = q.top();
            q.pop();
            for(int i = 0; i < 4; ++i) 
            {
                int r = t[0] + dirs[i][0];
                int c = t[1] + dirs[i][1];
                if(valid(r, c, R, C) && heightMap[r][c] != -1) 
                {
                    res += max(0, t[2] - heightMap[r][c]);
                    q.push({r, c, max(t[2], heightMap[r][c])});
                    heightMap[r][c] = -1;
                }
            }
        }
        return res;
    }
};

