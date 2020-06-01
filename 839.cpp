class Solution {
public:
    bool isSim(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++diff;
                if (diff > 2) return false;
            }
        }
        return true;
    }
    void dfs(vector<vector<int> >& g, int i, vector<bool>& seen) {
        seen[i] = true;
        for (auto j : g[i]) {
            if (!seen[j]) {
                dfs(g, j, seen);
            }
        }
    }
    int numSimilarGroups(vector<string>& A) {
        int N = A.size();
        vector<vector<int > > g(N);
        for (int i = 0; i < N; ++i) {
            g[i].push_back(i);
            for (int j = i + 1; j < N; ++j) {
                if (isSim(A[i], A[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<bool> seen(N, false);
        int res = 0;
        for (int i = 0; i < N; ++i) {
            if (!seen[i]) {
                ++res;
                dfs(g, i, seen);
            }
        }
        return res;
    }
};
