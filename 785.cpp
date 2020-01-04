class Solution 
{
public:
    bool dfs(const vector<vector<int>>& graph, vector<int>& cols, int i, int col) 
    {
        cols[i] = col;
        for(auto j : graph[i]) 
        {
            if(cols[j] == cols[i]) 
                return false;
            if(cols[j] == 0 && !dfs(graph, cols, j, -col)) 
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int N = graph.size();
        vector<int> cols(N, 0);
        for(int i = 0; i < N; ++i) 
        {
            if(cols[i] == 0 && !dfs(graph, cols, i, 1)) 
            {
                return false;
            }
        }
        return true;
    }
};

