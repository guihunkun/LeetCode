class Solution 
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
    {
        int R = A.size(), C = A[0].size();
        for(int i = 0; i < A.size(); i++)
        {
            reverse(A[i].begin(), A[i].end());
        }
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++)
            {
                if(A[r][c] == 1 )
                    A[r][c] = 0;
                else
                    A[r][c] = 1;
            }
        return A;
    }
};
