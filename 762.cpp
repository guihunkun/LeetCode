class Solution 
{
public:
    unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
    int bitsCount(int n) 
    {
        int res = 0;
        while(n > 0) 
        {
            n = n & (n - 1);
            ++res;
        }
        return res;
    }
    int countPrimeSetBits(int L, int R)
    {
        int res = 0;
        for(int i = L; i <= R; ++i) 
        {
            res += primes.find(bitsCount(i)) != primes.end();
        }
        return res;
    }
};

