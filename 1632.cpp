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
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        UnionFind uf(n * m);
        for (int i = 0; i < n; ++i) {
            map<int, vector<int>> mp;
            for (int j = 0; j < m; ++j)
                mp[matrix[i][j]].emplace_back(i * m + j);
            for (auto &[num, vec] : mp) {
                for (int k = 0; k + 1 < vec.size(); ++k)
                    uf.connect(vec[k], vec[k + 1]);
            }
        }
        for (int j = 0; j < m; ++j) {
            map<int, vector<int>> mp;
            for (int i = 0; i < n; ++i)
                mp[matrix[i][j]].emplace_back(i * m + j);
            for (auto &[num, vec] : mp) {
                for (int k = 0; k + 1 < vec.size(); ++k)
                    uf.connect(vec[k], vec[k + 1]);
            }
        }
        vector<vector<int>> adj(n * m);
        vector<int> indegree(n * m);
        for (int i = 0; i < n; ++i) {
            vector<pair<int, int>> v(m);
            for (int j = 0; j < m; ++j)
                v[j] = make_pair(matrix[i][j], j);
            sort(v.begin(), v.end());
            for (int j = 0; j + 1 < m; ++j)
                if (v[j].first != v[j + 1].first) {
                    int uu = uf.find(i * m + v[j].second);
                    int vv = uf.find(i * m + v[j + 1].second);
                    adj[uu].emplace_back(vv);
                    indegree[vv]++;
                }
        }
        for (int j = 0; j < m; ++j) {
            vector<pair<int, int>> v(n);
            for (int i = 0; i < n; ++i)
                v[i] = make_pair(matrix[i][j], i);
            sort(v.begin(), v.end());
            for (int i = 0; i + 1 < n; ++i)
                if (v[i].first != v[i + 1].first) {
                    int uu = uf.find(v[i].second * m + j);
                    int vv = uf.find(v[i + 1].second * m + j);
                    adj[uu].emplace_back(vv);
                    indegree[vv]++;
                }
        }
        vector<int> ans(n * m, 1);
        queue<int> q;
        for (int i = 0; i < n * m; ++i) {
            if (uf.find(i) == i && indegree[i] == 0)
                q.emplace(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                ans[v] = max(ans[v], ans[u] + 1);
                indegree[v]--;
                if (indegree[v] == 0)
                    q.emplace(v);
            }
        }
        vector<vector<int>> result(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                result[i][j] = ans[uf.find(i * m + j)];
        return result;
    }
};

