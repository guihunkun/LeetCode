class Solution {
public:
    using ll = long long;
    const ll M = 1e9 + 7;
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        ll res = 0;
        ll m = 1;
        for (int i = 0; i < A.size(); ++i) {
            res += A[i] * m;
            res %= M;
            m <<= 1;
            m %= M;
        }
        m = 1;
        for (int i = A.size() - 1; i >= 0; --i) {
            res -= A[i] * m;
            res %= M;
            m <<= 1;
            m %= M;
        }
        res = (res + M) % M;
        return res;
    }
};
