//leetcode
struct BIT 
{
    vector<int> a;
    int n;
    
    BIT(int _n): n(_n), a(_n + 1) {}
    
    static int lowbit(int x) {
        return x & (-x);
    }

    int query(int x) const {
        int ret = 0;
        while (x) {
            ret += a[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void update(int x, int dt) {
        while (x <= n) {
            a[x] += dt;
            x += lowbit(x);
        }
    }
};

class Solution 
{
public:
    vector<int> processQueries(vector<int>& queries, int m) 
    {
        int n = queries.size();
        BIT bit(m + n);
        
        vector<int> pos(m + 1);
        for (int i = 1; i <= m; ++i) {
            pos[i] = n + i;
            bit.update(n + i, 1);
        }
        
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int& cur = pos[queries[i]];
            bit.update(cur, -1);
            ans.push_back(bit.query(cur));
            cur = n - i;
            bit.update(cur, 1);
        }
        return ans;
    }
};
