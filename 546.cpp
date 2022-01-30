class Solution 
{
public:
    int removeBoxes(vector<int>& boxes) 
    {
        int len = boxes.size();
        int dp[100][100][100] = {0};
        for(int i = 0; i < len; i++) 
        {
            for(int k = 0; k <= i; k++) {
                dp[i][i][k] = (k + 1) * (k + 1);
            }
        }
        for(int l = 1; l < len; l++) 
        {
            for(int j = l; j < len; j++) 
            {
                int i = j - l;
                for(int k = 0; k <= i; k++) 
                {
                    int res = (k + 1) * (k + 1) + dp[i + 1][j][0];
                    for(int m = i + 1; m <= j; m++) 
                    {
                        if (boxes[m] == boxes[i]) 
                        {
                            res = max(res, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
                        }
                    }
                    dp[i][j][k] = res;
                }
            }
        }
        return dp[0][len - 1][0];
    }
};
