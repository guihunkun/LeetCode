class Solution 
{
public:
    int largestPalindrome(int n) 
    {
        if(n == 1)
            return 9;
        int max = 1;
        while(n-- > 0)
            max*=10;
        for(int i = max-2; i > 0; --i)
        {
            long u = i;
            long u2 = i;
            while(u2 > 0)
            {
                u = u*10+u2%10;
                u2 /= 10;
            }
            u2 = max-1;
            while(u2 > 0 && u2*u2 > u)
            {
                if(u%u2 == 0)
                    return (int) (u%1337);
                if(u2%10 == 9)
                {
                    u2-=2;
                }
                else
                    u2-=4;
            }
        }
        return 0;
    }
};
