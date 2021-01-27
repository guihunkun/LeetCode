//leetcode
// ���鼯ģ��
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // ��ǰ��ͨ������Ŀ
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind ufa(n), ufb(n);
        int ans = 0;

        // �ڵ��Ÿ�Ϊ�� 0 ��ʼ
        for (auto& edge: edges) {
            --edge[1];
            --edge[2];
        }

        // ������
        for (const auto& edge: edges) {
            if (edge[0] == 3) {
                if (!ufa.unite(edge[1], edge[2])) {
                    ++ans;
                }
                else {
                    ufb.unite(edge[1], edge[2]);
                }
            }
        }

        // ��ռ��
        for (const auto& edge: edges) {
            if (edge[0] == 1) {
                // Alice ��ռ��
                if (!ufa.unite(edge[1], edge[2])) {
                    ++ans;
                }
            }
            else if (edge[0] == 2) {
                // Bob ��ռ��
                if (!ufb.unite(edge[1], edge[2])) {
                    ++ans;
                }
            }
        }

        if (ufa.setCount != 1 || ufb.setCount != 1) {
            return -1;
        }
        return ans;
    }
};

