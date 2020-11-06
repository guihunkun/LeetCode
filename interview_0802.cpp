
class Solution
{
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        /*
         * 动态规划
         * 移动方向决定了当前坐标只能够从垂直向上的一个坐标或者左边的一个坐标达来到
         * 左边的第一列，只能从上往下 dp[i][0] = !obstacleGrid[i-1][0] && dp[i-1][0]
         * 上面的第一行，只能从左往右 dp[0][j] = !obstacleGrid[0][j-1] && dp[0][j-1]
         * 状态转移方程 ：dp[i][j] = dp[i-1][j] || dp[i][j-1]
         * 
         * dp[row][col] == 1, 说明存在路径从起点到终点，根据dp矩阵就能逆推回去得到一条路径
         */

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int> > res;
        //起点和终点是障碍
        if(obstacleGrid[0][0] || obstacleGrid[row-1][col-1])
            return res;
        vector<vector<bool> > dp(row, vector<bool>(col, false));
        dp[0][0] = true;
        //初始化首列
        for(int r = 1; r < row; r++)
        {
            dp[r][0] = !obstacleGrid[r][0] && dp[r - 1][0];
        }
        //初始化首行
        for(int c = 1; c < col; c++)
        {
            dp[0][c] = !obstacleGrid[0][c] && dp[0][c - 1];
        }
        for(int i = 1; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                dp[i][j] = !obstacleGrid[i][j] && (dp[i - 1][j] || dp[i][j - 1]);
            }
        }
        //如果终点不可达
        if(!dp[row-1][col-1])
            return res;
        int r = row-1, c = col-1;
        while(r > 0 || c > 0)
        {
            res.push_back({r, c});
            //先考虑上面的坐标, 不管是先上面还是左边，只要坐标可用，最终肯定能回到起点(这是前面动态递推的结果)
            if(r > 0 && dp[r - 1][c])
                r--;
            else if(c > 0 && dp[r][c - 1])
                c--;
        }
        res.push_back({0, 0});

        reverse(res.begin(), res.end());
        return res;
    }
};
