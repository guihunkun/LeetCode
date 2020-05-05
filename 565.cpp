class Solution {
public:
    struct DSU {
        vector<int> S;
        vector<int> F;
        int father(int x) {
            if (x != F[x]) F[x] = father(F[x]);
            return F[x];
        }
        void unite(int x, int y) {
            int fx = father(x);
            int fy = father(y);
            if (fx != fy) {
                F[fx] = fy;
                S[fy] += S[fx];
                S[fx] = 0;
            }
        }
        DSU (int n) {
            S = vector<int>(n, 1);
            F = vector<int>(n, 0);
            for (int i = 0; i < n; ++i) {
                F[i] = i;
            }
        }
    };
    int arrayNesting(vector<int>& nums) {
        int N = nums.size();
        auto dsu = DSU(N);
        for (int i = 0; i < N; ++i) {
            dsu.unite(i, nums[i]);
        }
        return *max_element(dsu.S.begin(), dsu.S.end());
    }
};
