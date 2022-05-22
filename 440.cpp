class Solution 
{
public:
    int findKthNumber(int n, int k) 
    {
        int cur = 1;
        --k;
        while(k>0)
        {
            long long first = cur, last = cur + 1, step = 0;
            while(first<=n)
            {
                step += min((long long)n+1,last) - first;
                first *= 10;
                last *= 10;
            }
            if(step <= k)
            {
                k -= step;
                cur++;
            }
            else
            {
                k--;
                cur *= 10;
            }
        }
        return cur;
    }
};
