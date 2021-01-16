class UnionFind {
private:
    vector<int> f, sz;
public:
    UnionFind(int n): f(n), sz(n) {
        for (int i = 0; i < n; i++) {
            f[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (f[x] == x) {
            return x;
        }
        int newf = find(f[x]);
        f[x] = newf;
        return f[x];
    }

    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return;
        }
        f[fx] = fy;
        sz[fy] += sz[fx];
    }

    int size(int x) {
        return sz[find(x)];
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int h = grid.size(), w = grid[0].size();
        
        UnionFind uf(h * w + 1);
        vector<vector<int>> status = grid;
        for (int i = 0; i < hits.size(); i++) {
            status[hits[i][0]][hits[i][1]] = 0;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (status[i][j] == 1) {
                    if (i == 0) {
                        uf.merge(h * w, i * w + j);
                    }
                    if (i > 0 && status[i - 1][j] == 1) {
                        uf.merge(i * w + j, (i - 1) * w + j);
                    }
                    if (j > 0 && status[i][j - 1] == 1) {
                        uf.merge(i * w + j, i * w + j - 1);
                    }
                }
            }
        }
        const vector<pair<int, int>> directions{{0, 1},{1, 0},{0, -1},{-1, 0}};
        vector<int> ret(hits.size(), 0);
        for (int i = hits.size() - 1; i >= 0; i--) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) {
                continue;
            }
            int prev = uf.size(h * w);

            if (r == 0) {
                uf.merge(c, h * w);
            }
            for (const auto [dr, dc]: directions) {
                int nr = r + dr, nc = c + dc;
                
                if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                    if (status[nr][nc] == 1) {
                        uf.merge(r * w + c, nr * w + nc);
                    }
                }
            }
            int size = uf.size(h * w);
            ret[i] = max(0, size - prev - 1);
            status[r][c] = 1;
        }
        return ret;
    }
};
