class Solution 
{
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    {
        vector<pair<int, int> > dire = {{0,1},{1,0},{0,-1},{-1,0}};
        set<pair<int, int> > ob;
        int i = 0, x = 0, y = 0, maxdis = 0;
        for(vector<int> vi : obstacles)
            ob.insert(make_pair(vi[0], vi[1]));
        for(int com : commands)
        {
            if(com == -2)
                i = (i + 3) % 4;
            else if(com == -1)
                i = (i + 1) % 4;
            else
            {
                while(com)
                {
                    int dx = x + dire[i].first;
                    int dy = y + dire[i].second;
                    if(ob.find(make_pair(dx, dy)) == ob.end())
                    {
                        x = dx;
                        y = dy;
                        maxdis=max(maxdis,x*x+y*y);
                    }
                    else
                        break;
                    com--;
                }
            }
        }
        return  maxdis;
    }
};
