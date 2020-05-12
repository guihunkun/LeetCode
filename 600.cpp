class Solution {
public:
    int M[32][2][2];
    int D[32];
    int N;
    int dp(int k, int limit, int prev) {
        if (M[k][limit][prev] != -1) return M[k][limit][prev];
        if (k == N) return 1;
        M[k][limit][prev] = 0;
        for (int i = 0; i <= (limit ? D[k] : 1); ++i) {
            if (i == 1 && prev == 1) continue;
            M[k][limit][prev] += dp(k + 1, limit && (i == D[k]), i);
        }
        return M[k][limit][prev];
    }
    int findIntegers(int num) {
        memset(M, -1, sizeof(M));
        for (N = 0; num > 0; ++N, num >>= 1) {
            D[N] = num & 1;
        }
        reverse(D, D + N);
        return dp(0, 1, 0);
    }
};
