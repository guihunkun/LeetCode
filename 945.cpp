class Solution 
{
public:
    int minIncrementForUnique(vector<int>& A) 
    {
        sort(A.begin(), A.end());
        int ans = 0, taken = 0;
        for(int i = 1; i < A.size(); ++i) 
        {
            if(A[i-1] == A[i]) 
            {
                taken++;
                ans -= A[i];
            } 
            else 
            {
                int give = min(taken, A[i] - A[i - 1] - 1);
                ans += give * (give + 1) / 2 + give * A[i-1];
                taken -= give;
            }
        }
        if(A.size() > 0) 
        {
            ans += taken * (taken + 1) / 2 + taken * A.back();
        }
        return ans;
    }
};

