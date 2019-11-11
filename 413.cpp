class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        int n = A.size();
        if(n < 3) 
        {
            return 0;
        }
        int start = 0, count = 0;
        int diff = A[1] - A[0];
        for(int i = 2; i < n; i++) 
        {
            if(A[i] - A[i-1] == diff)
            {
                if( i - start + 1 >= 3) 
                {
                    count += (i - start + 1) - 2;
                }
            }
            else 
            {
                diff = A[i] - A[i-1];
                while ( start < i && A[start+1] - A[start] != diff)
                {
                    start++;
                }
            }
        }
        return count;
    }
};
