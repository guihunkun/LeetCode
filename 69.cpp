class Solution {
public:
    int mySqrt(int x) 
    {
        if(x == 0 || x == 1)
            return x;
        long long start = 0, end = x;
        while(start + 1 < end)
        {
            long long mid = start + (end - start) / 2;
            if(mid*mid == x)
                return mid;
            else if(mid * mid < x)
                start = mid;
            else
                end = mid;
        }
        if(end * end <= x)
            return end;
        return start;
    }
};
