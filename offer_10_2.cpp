class Solution 
{
public:
    int numWays(int n) 
    {
        if(n == 0 || n == 1)
            return 1;
        int res = 0;
        int a = 1, b = 1;
        while(n >= 2)
        {
            res = (a+b)%1000000007;
            b = a;
            a = res;
            n--;
        }
        return res;
    }
};
