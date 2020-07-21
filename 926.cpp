class Solution 
{
public:
    int minFlipsMonoIncr(string S) 
    {
        int res = INT_MAX;
        int n = S.size();
        vector<int> rec(n + 1);
        for(int i = 0; i < n; i++)
        {
            rec[i+1] = rec[i] + (S[i] == '1' ? 1 : 0);
        }
        for(int i= 0; i < n+1; i++)
        {
            res = min(res, rec[i] + n - i - (rec[n] - rec[i]));
        }
        return res;
    }
};

