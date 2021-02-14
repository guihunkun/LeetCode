class Solution {
public:
    int getf(vector<int>& f, int x) {
        if (f[x] == x) {
            return x;
        }
        int newf = getf(f, f[x]);
        f[x] = newf;
        return newf;
    }

    void add(vector<int>& f, int x, int y) {
        int fx = getf(f, x);
        int fy = getf(f, y);
        f[fx] = fy;
    }

    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int tot = n / 2;
        vector<int> f(tot, 0);
        for (int i = 0; i < tot; i++) {
            f[i] = i;
        }

        for (int i = 0; i < n; i += 2) {
            int l = row[i] / 2;
            int r = row[i + 1] / 2;
            add(f, l, r);
        }

        unordered_map<int, int> m;
        for (int i = 0; i < tot; i++) {
            int fx = getf(f, i);
            m[fx]++;
        }
        
        int ret = 0;
        for (const auto& [f, sz]: m) {
            ret += sz - 1;
        }
        return ret;
    }
};
