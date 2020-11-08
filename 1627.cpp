class UnionFind {
  int n;
  vector<int> parent, size;

public:
  UnionFind(int n) {
    this->n = n;
    parent = vector<int>(n);
    size = vector<int>(n, 1);
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  int find(int idx) {
    if (parent[idx] == idx)
      return idx;
    return parent[idx] = find(parent[idx]);
  }

  void connect(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa != fb) {
      if (size[fa] > size[fb]) {
        parent[fb] = fa;
        size[fa] += size[fb];
      } else {
        parent[fa] = fb;
        size[fb] += size[fa];
      }
    }
  }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        UnionFind uf(n + 1);
        for (int i = threshold + 1; i <= n; ++i)
            for (int j = 2 * i; j <= n; j += i)
                uf.connect(i, j);
        vector<bool> ans;
        for (auto &q : queries) {
            int u = q[0], v = q[1];
            int fu = uf.find(u), fv = uf.find(v);
            ans.emplace_back(fu == fv);
        }
        return ans;
    }
};

