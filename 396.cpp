class Solution
{
public:
    int maxRotateFunction(vector<int>& A) 
    {
        int n = A.size();
        long tmpsum = 0, s = 0;
        for (int i = 0; i < n; i++)
        {
            tmpsum += A[i];
            s += i * A[i];
        }
        
        long res = s;
        for (int i = n - 1; i > 0; i--)
        {
            s += tmpsum - n * (long)A[i];
            res = max(res, s);
        }
        return res;
    }
};
