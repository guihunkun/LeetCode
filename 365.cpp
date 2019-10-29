class Solution 
{
public:
    int gcd(int a, int b)
    {
        if(a < b)
        {
            swap(a,b);
        }
        if(a % b == 0)
            return b;
        else
            return gcd(b,a%b);
    }
    bool canMeasureWater(int x, int y, int z) 
    {
        if(z == 0)
            return true;
        if(x == 0 || y == 0)
            return (x+y) == z;
        if(z > (x+y))
            return false;
        return z % gcd(x,y) == 0;
    }
};
