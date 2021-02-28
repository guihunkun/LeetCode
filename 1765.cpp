class Solution 
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int R = isWater.size();
        int C = isWater[0].size();
        vector<vector<int> > res(R, vector<int>(C, 0));
        queue<tuple<int, int>> que;
        for(int r = 0; r < R; r ++)
        {    
            for(int c = 0; c < C; c ++) {
                if(isWater[r][c] == 1) {
                    que.push(make_tuple(r,c)); //从水出发,高度为0的点们
                }
            }
        }
        while(que.size()) //多源BFS + 记忆化
        {
            auto [r,c] = que.front();   que.pop();
            for (auto [nr, nc] : vector<tuple<int,int>>{{r-1,c},{r,c+1},{r+1,c},{r,c-1}})
            {
                if (0 <= nr && nr < R && 0 <= nc && nc < C && isWater[nr][nc] == 0)
                {
                    res[nr][nc] = res[r][c] + 1;
                    isWater[nr][nc] = 1;            //天然的记忆化visited数组  染色法 的思想
                    que.push(make_tuple(nr,nc));
                }
            }
        }
        return res;
    }
};

