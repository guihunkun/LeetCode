class Solution 
{
public:
    bool isPerfectSquare(int num) 
    {
        long long r = num / 2 + 1;
        while(r * r > num)
            r = (r + num / r) / 2;
        return r *r == num;
    }
};
