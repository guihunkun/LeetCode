class Solution 
{
public:
    int ans = 0;
    int numWays(int n, vector<vector<int>>& relation, int k) 
    {
        vector<vector<int> > v(n);
        for(auto r : relation)
            v[r[0]].push_back(r[1]);
        dfs(n - 1, v, k, 0, 0); 
        return ans;
    }

    void dfs(int n, vector<vector<int>> v, int dis, int deep, int pos) {
        if(deep == dis) 
        {
            if(pos == n) 
                ++ans;
            return;
        }

        for(int topos : v[pos])
            dfs(n, v, dis, deep + 1, topos);
        return;
    }
};
