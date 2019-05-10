class Solution 
{
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) 
    {
        vector<vector<int>> At(A[0].size(),vector<int>(A.size()));
        for(int i = 0; i < A[0].size(); i++)
            for(int j = 0 ;j < A.size(); j++)
                At[i][j]=A[j][i];
        return At;
    }
};
