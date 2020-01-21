class Solution {
public:
    const int M1 = 0xCCCCCCCC; // 1100110011001100...
    const int M2 = 0x33333333; // 0011001100110011...
    const int INF = 1e8;
    unordered_map<char, int> m{{'A', 0}, {'T', 1}, {'C', 2}, {'G', 3}};
    int toInt(const string& s) {
        int n = 0;
        for (auto c : s) {
            n <<= 2;
            n |= m[c];
        }
        return n;
    }
    bool valid(int x, int y) {
        int t = x ^ y;
        // 突变不能跨越点
        if ((t & M1) && (t & M2)) return false;
        long b = t & (-t);
        // 突变的点不能超过2个
        return (b << 2) > t;
    }
    void dfs(unordered_map<int, vector<int> >& g, int x, unordered_map<int, int>& dfn) {
        for (auto y : g[x]) {
            if (dfn[x] + 1 < dfn[y]) {
                dfn[y] = dfn[x] + 1;
                dfs(g, y, dfn);
            }
        }
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int ns = toInt(start);
        int ne = toInt(end);
        vector<int> nbs;
        for (auto& s : bank) {
            nbs.push_back(toInt(s));
        }
        unordered_map<int, vector<int> > g;
        int N = nbs.size();
        for (int i = 0; i < N; ++i) {
            if (valid(ns, nbs[i])) {
                g[ns].push_back(nbs[i]);
            }
            for (int j = 0; j < i; ++j) {
                if (valid(nbs[i], nbs[j])) {
                    g[nbs[i]].push_back(nbs[j]);
                    g[nbs[j]].push_back(nbs[i]);
                }
            }
        }
        unordered_map<int, int> dfn;
        for (auto x : nbs) dfn[x] = INF;
        dfn[ne] = INF;
        dfn[ns] = 0;
        dfs(g, ns, dfn);
        return dfn[ne] == INF ? -1 : dfn[ne];
    }
};
