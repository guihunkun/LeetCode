class Solution 
{
public:
    int f(int n, int m)
    {
        if(n == 1)
        {
            return 0;
        }
        int x = f(n-1, m);
        return (x+m)%n;
    }
    int lastRemaining(int n, int m) 
    {
        return f(n, m);
    }
};
