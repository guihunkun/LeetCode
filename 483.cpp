#define LL long long

class Solution 
{
public:
    string smallestGoodBase(string N) 
    {
        // (11...11)k = k^{s} + k^{s-1} + ... + k^1 + k^0 = n
        // k^s < n < (k+1)^s
        // k < n^{1/s} < k+1
        
        LL n = stol(N);
        LL ans = n - 1;   // 将答案置为 s=1 的情况
        for(int s = 59; s >= 2; --s) 
        {
            int k = pow(n, 1.0 / s);   // k 为 n^{1/s} 的整数部分
            if(k > 1) 
            {    // 判断 k 是否是一个合法的进制
                LL sum = 1, mul = 1;   // 计算 (11...11)k 对应的十进制值
                for(int i = 1; i <= s; ++i) 
                {
                    mul *= k;
                    sum += mul;
                }
                if(sum == n) 
                {
                    ans = k;
                    break;
                }
            }
        }
        return to_string(ans);
    }
};
