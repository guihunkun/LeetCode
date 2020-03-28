class Solution 
{
private:
    // 一个用来判断有没有被记录， 一个存放记录
    bitset< 1<<20 > used, val;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) 
    {
        int iMax = maxChoosableInteger, tar = desiredTotal;
        if(tar > iMax*(iMax+1) / 2) 
            return false;
        if(iMax >= tar) 
            return true;

        return helper(iMax, tar, 0);
    }
    bool helper(int iMax, int tar, int mask)
    {
        if(used[mask]) 
        return val[mask];
        // 倒着查找 更快一些
        for(int i=iMax, cur = 1; i > 0; i--, cur <<= 1)
            if((mask & cur) == 0)
                if(i >= tar || !helper(iMax, tar-i, mask|cur))
                    return used[mask] = val[mask] = 1;

        used[mask] = 1, val[mask] = 0;
        return false;
    }
};
