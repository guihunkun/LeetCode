class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        int prefix = 0, suffix = 0;
        int base = 31, mod = 1000000007, mul = 1;
        int happy = 0;
        for (int i = 1; i < n; ++i) {
            prefix = ((long long)prefix * base + (s[i - 1] - 97)) % mod;
            suffix = (suffix + (long long)(s[n - i] - 97) * mul) % mod;
            if (prefix == suffix) {
                happy = i;
            }
            mul = (long long)mul * base % mod;
        }
        return s.substr(0, happy);
    }
};
