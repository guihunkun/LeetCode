class Solution 
{
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) 
    {
        unordered_set<long> s;
        int xx = 0,yy = 0;
        s.insert(0);
        for(auto c : command){
            if(c == 'U') 
                yy++;
            else if(c == 'R')
                xx++;
            s.insert(((long)xx << 30) | yy);
        }
        int circle = min(x/xx,y/yy);
        if(s.count(((long)(x-circle*xx) << 30) | (y-circle*yy)) == 0) 
            return false;    
        for(auto v: obstacles){
            if(v.size() != 2) 
                continue;
            if(v[0] > x || v[1] > y) 
                continue;
            circle = min(v[0]/xx,v[1]/yy);
            if(s.count(((long)(v[0]-circle*xx) << 30) | (v[1]-circle * yy))) 
                return false;
        }
        return true;
    }
};
