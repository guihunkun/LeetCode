class Solution 
{
public:
    double recPow(double x, long n)
    {
        if(n == 1)
            return x;
        double val = recPow(x, n / 2);
        return (val * val * (n % 2 ? x : 1));
    }
    double myPow(double x, int n) 
    {
        if(n == 0)
            return 1;
        double res = recPow(x, abs(long(n)));
        return (n > 0 ? res : 1 / res);
    }
};
