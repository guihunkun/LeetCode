class Solution 
{
public:
    int arrangeCoins(int n)
    {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        long sum = 0;
        int i = 1; 
        while(sum <= n)
        {
            sum = sum + i;
            i++;
        }
        return i-2;
    }
};

