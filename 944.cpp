class Solution 
{
public:
    int minDeletionSize(vector<string>& A) 
    {
        int res = 0;
        for(int j = 0; j < A[0].size(); j++)
            for(int i = 1; i < A.size(); i++)
            {
                if(A[i-1][j] > A[i][j])
                {
                    res++;
                    break;
                }
            }
        return res;
    }
};
