class Solution {
public:
    vector<int> fa, siz;
    int v[100005], ans;
    bool vis[100005];
    int Find(int x){
        return (x == fa[x] ? x: (fa[x] = Find(fa[x])));
    }
    void Union(int x, int y){
        int fx = Find(x), fy = Find(y);
        if (fx == fy) return ;
        if (siz[fx] > siz[fy]){
            fa[fy] = fx, siz[fx] += siz[fy], ans = max(ans, siz[fx]);
        }else {
            fa[fx] = fy, siz[fy] += siz[fx], ans = max(ans, siz[fy]);
        }
    }
    int largestComponentSize(vector<int>& A) {
        int n = A.size(), maxi = -1;
        memset(v, -1, sizeof(v));
        memset(vis, 0, sizeof(vis));
        fa = vector<int>(n, 0);
        siz = vector<int>(n, 1);
        ans = 0;
        for (int i = 0; i < n; ++i)
            fa[i] = i, v[A[i]] = i, maxi = max(maxi, A[i]);
        for (int i = 2; i <= maxi; ++i){
            if (!vis[i]){
                int t = -1;
                if (v[i] >= 0) t = v[i];
                for (int j = i + i; j <= maxi; j += i){
                    if (v[j] >= 0) {
                        if (t < 0) t = v[j];
                        else Union(t, v[j]);
                    }
                    vis[j] = true;
                }
            }
        }
        return ans;
    }
};
