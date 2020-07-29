class Solution 
{
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) 
    {
        int p = m+n-1;
        m--;
        n--;
        while(m >=0 && n >= 0)
        {
            if(A[m] >= B[n])
            {
                A[p--] = A[m--];
            }
            else
            {
                A[p--] = B[n--];
            }
        }
        while(n != -1)
        {
            A[p--] = B[n--];
        }
        while(m != -1)
        {
            A[p--] = A[m--];
        }
    }
};
