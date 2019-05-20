/*
class Solution 
{
public:
    bool judgeSquareSum(int c) 
    {
        assert(c >= 0);
        if(c == 0)
            return true;
        for(long long a = 0; a * a <= c; a++)
        {
            double b = sqrt(c - a * a);
            if(b == (int)b)
                return true;
        }
        return false;
    }
};
*/
class Solution 
{
public:
    bool judgeSquareSum(int c) 
    {
        assert(c >= 0);
        if(c == 0)
            return true;
        for(int i = 2; i * i <= c; i++) 
        {
            int count = 0;
            if (c % i == 0) 
            {
                while (c % i == 0) 
                {
                    count++;
                    c /= i;
                }
                if (i % 4 == 3 && count % 2 != 0)
                    return false;
            }
        }
        return c % 4 != 3;
    }
};
