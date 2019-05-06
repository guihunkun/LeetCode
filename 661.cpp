class Solution 
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) 
    {
        int R = M.size(), C = M[0].size();
        vector<vector<int>> ans(R, vector<int>(C));

        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++) 
            {
                int count = 0;
                for(int nr = r-1; nr <= r+1; nr++)
                    for(int nc = c-1; nc <= c+1; nc++) 
                    {
                        if(0 <= nr && nr < R && 0 <= nc && nc < C) 
                        {
                            ans[r][c] += M[nr][nc];
                            count++;
                        }
                    }
                ans[r][c] /= count;
            }
        return ans;
    }
};
