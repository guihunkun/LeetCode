class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int N = matrix.size();
        vector<vector<int> > res = matrix;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                res[j][N-i-1] = matrix[i][j];
            }
        }
        matrix = res;
    }
};
