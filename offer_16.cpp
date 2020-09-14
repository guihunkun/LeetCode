class Solution 
{
public:
    double myPow(double x, int n) 
    {
        if(x == 0) 
            return 0;
        long long b = n;
        double res = 1.0;
        if(b < 0) 
        {
            x = 1.0 / x;
            b = -b;
        }
        while(b > 0) 
        {
            if((b & 1) == 1) 
                res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
};
