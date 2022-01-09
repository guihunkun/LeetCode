class Solution 
{
public:
    int kthGrammar(int N, int K) 
    {
        return helper(N, K, 0);
    }

    int helper(int N, int K, int flag) 
    {
        if(N == 1) return flag;
        int half = (1 << (N-2));
        if(K <= half) {
            return helper(N-1, K, flag);
        } else {
            return helper(N-1, K - half, 1-flag);
        }
    }
};



