class Solution 
{
public:
    // Hierholzer 算法
    void dfs(vector<vector<int> >& g, int i, int N, vector<int>& path) 
    {
        for(int j = 0; j < N; ++j) 
        {
            if(g[i][j] > 0) 
            {
                --g[i][j];
                dfs(g, j, N, path);
            }
        }
        path.push_back(i);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        // 排序、去重、ID化
        vector<string> cities;
        for(auto& t : tickets) 
        {
            cities.push_back(t[0]);
            cities.push_back(t[1]);
        }
        sort(cities.begin(), cities.end());
        cities.erase(unique(cities.begin(), cities.end()), cities.end());
        int N = cities.size();
        map<string, int> m;
        for(int i = 0; i < N; ++i) 
        {
            m[cities[i]] = i;
        }
        // 构建有向图
        vector<vector<int> > g(N, vector<int>(N, 0));
        for(auto& t : tickets) 
        {
            ++g[m[t[0]]][m[t[1]]];
        }
        // 深度优先搜索得到最终路径
        vector<int> path;
        dfs(g, m["JFK"], N, path);
        vector<string> res;
        for(auto i : path) 
        {
            res.push_back(cities[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
