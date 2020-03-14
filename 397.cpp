class Solution 
{
public:
    int integerReplacement(int n) 
    {
        int ret = 0;
        while(n > 3)
        {
            if(n % 2)
            {
                n >>= 1;
                if(n % 2) 
                    n++;
                ret += 2;
            }
            else
            {
                n >>= 1;
                ret++;
            }
        }
        return ret + n - 1;
    }
};

