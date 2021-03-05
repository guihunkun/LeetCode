class Solution {
public:
    set<int> ss[100010];
    int vis[100010];
    bool dfs(int curr,int target)
    {
        bool ret=false;
        if(curr == target) return true;

        //标记当前点已经访问过
        vis[curr] = 1;
        for(auto& e:ss[curr]) {
            if(vis[e] != 1) {
                ret = dfs(e,target);
                if(ret) 
                    return ret;
            }      
        }

        return false;
    }

    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        for(int i =0; i < graph.size();i++) {
            int a=graph[i][0]; 
            int b = graph[i][1];
            ss[a].insert(b);
        }
        return dfs(start,target);
    }
};

