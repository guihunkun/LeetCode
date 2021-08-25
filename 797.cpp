class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> stk;

    void dfs(vector<vector<int>>& graph, int x, int n) 
    {
        if(x == n) {
            ans.push_back(stk);
            return;
        }
        for(auto& y : graph[x]) {
            stk.push_back(y);
            dfs(graph, y, n);
            stk.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        stk.push_back(0);
        dfs(graph, 0, graph.size() - 1);
        return ans;
    }
};
