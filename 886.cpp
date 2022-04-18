class Solution 
{
public:
    bool dfs(int f, int flag, vector<int>& color, vector<vector<int>>& graph) 
    {
        if(color[f] != -1 && color[f] != flag) 
        {
            return false;
        }
        if(color[f] == flag) 
        {
            return true;
        }
        color[f] = flag;
        for(int i = 0; i < graph[f].size(); i++) 
        {
            int b = graph[f][i];
            bool res = dfs(b, flag^1, color, graph);
            if(!res) 
            {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes)
    {
        vector<vector<int> > graph(N+1, vector<int>());
        for(int i = 0; i < dislikes.size(); ++i)
        {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(N + 1, -1);
        for(int i = 0; i < dislikes.size(); ++i) 
        {
            int a = dislikes[i][0];
            if(color[a] == -1) 
            {
                if(!dfs(a, 0, color, graph))
                {
                    return false;
                }  
            }
        }
        return true;
    }
};


