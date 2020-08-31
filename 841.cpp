class Solution 
{
private:
    vector<bool> _vis;
    int _num;
public:
    void dfs(vector<vector<int> >& rooms, int index)
    {
        _vis[index] = true;
        _num++;
        for(auto& id : rooms[index])
        {
            if(!_vis[id])
            {
                dfs(rooms, id);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        _num = 0;
        _vis.resize(n);
        dfs(rooms, 0);
        return n == _num;
    }
};
