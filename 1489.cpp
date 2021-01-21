//leetcode
// 并查集模板
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // 当前连通分量数目
    int setCount;
    
public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }
    
    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }
    
    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const auto& u, const auto& v) {
            return u[2] < v[2];
        });

        // 计算 value
        UnionFind uf_std(n);
        int value = 0;
        for (int i = 0; i < m; ++i) {
            if (uf_std.unite(edges[i][0], edges[i][1])) {
                value += edges[i][2];
            }
        }

        vector<vector<int>> ans(2);
        
        for (int i = 0; i < m; ++i) {
            // 判断是否是关键边
            UnionFind uf(n);
            int v = 0;
            for (int j = 0; j < m; ++j) {
                if (i != j && uf.unite(edges[j][0], edges[j][1])) {
                    v += edges[j][2];
                }
            }
            if (uf.setCount != 1 || (uf.setCount == 1 && v > value)) {
                ans[0].push_back(edges[i][3]);
                continue;
            }

            // 判断是否是伪关键边
            uf = UnionFind(n);
            uf.unite(edges[i][0], edges[i][1]);
            v = edges[i][2];
            for (int j = 0; j < m; ++j) {
                if (i != j && uf.unite(edges[j][0], edges[j][1])) {
                    v += edges[j][2];
                }
            }
            if (v == value) {
                ans[1].push_back(edges[i][3]);
            }
        }
      
        return ans;
    }
};

