class Solution 
{
public:
    int shortestSubarray(vector<int>& A, int K) 
    {
        if (A.size() < 1)return -1;

        int st = 0;
        int en = 0;
        int res = INT_MAX;
        int sum[A.size() + 1];
        int q[A.size() + 1];

        sum[0] = 0;

        for (int i = 0; i < A.size(); ++i) 
            sum[i + 1] = sum[i] + A[i];

        for (int i = 0; i < A.size() + 1; ++i)
        {
            if (en == st) 
                q[en++] = i;
            else 
            {
                while(en != st && sum[i] <= sum[q[en - 1]]) 
                    --en;
                while(en != st && sum[i] - sum[q[st]] >= K)
                {
                    res = min(res, i - q[st]);
                    ++st;
                }
                q[en++] = i;
            }
        }
        return res == INT_MAX ? -1 : res;
        
    }
};
