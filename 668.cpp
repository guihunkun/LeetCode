class Solution 
{
public:
    int findKthNumber(int m, int n, int k) 
    {
        int start = 1, end = m*n;
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            if(count(mid, m, n, k))
                end = mid;
            else
                start = mid;
        }
        if(count(start, m, n, k))
            return start;
        return end;
    }
    bool count(int mid, int m, int n, int k)
    {
        int res = 0;
        for(int i = 1; i <= m; i++)
        {    
            if(mid / i == 0)
                break;
            res += min(mid / i, n);
        }
        return res >= k;
    }
};
