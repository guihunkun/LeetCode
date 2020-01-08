class Solution
{
public:
    bool hasAlternatingBits(int n) 
    {
        long long res = n^(n>>1);
        return ((res & (long long)(res+1)) == 0);
    }
};
