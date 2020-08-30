class Solution 
{
public:
    int fib(int n) 
    {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int res = 0, a = 1, b = 0;
        while(n >= 2)
        {
            res = (a+b)% 1000000007;
            b = a;
            a = res;
            n--;
        }
        return res;
    }
};
