class Solution 
{
public:
    int matrixScore(vector<vector<int>>& A) 
    {
        int m = A.size(), n = A[0].size();
        int ret = m * (1 << (n - 1));

        for(int j = 1; j < n; j++) 
        {
            int nOnes = 0;
            for(int i = 0; i < m; i++) 
            {
                if (A[i][0] == 1) {
                    nOnes += A[i][j];
                } else {
                    nOnes += (1 - A[i][j]); // 如果这一行进行了行反转，则该元素的实际取值为 1 - A[i][j]
                }
            }
            int k = max(nOnes, m - nOnes);
            ret += k * (1 << (n - j - 1));
        }
        return ret;
    }
};
