
/*
class Solution 
{
public:
    int numTrees(int n) 
    {
        vector<int> memo(n + 1);
        memo[0] = 1;
        memo[1] = 1;
        for(int i = 2; i < n + 1; i++)
            for(int j = 0; j < i; j++)
                memo[i] = memo[i] + memo[j] * memo[i - j - 1];
        return memo[n];
    }
};
*/
class Solution 
{
public:
    int numTrees(int n) 
    {
        long long ans=1;
        for(int i = n + 1; i <= 2 * n; i++)
        {
            ans = ans * i / (i-n);
        }
        return ans / (n+1);
    }
};

