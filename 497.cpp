class Solution 
{
    map<long, vector<int>> data;
    long max_pick = 0;
public:
    Solution(vector<vector<int>>& rects) 
    {            
        long last = 0;
        for (auto& rect: rects)
        {
            long size = (abs(rect[2] - rect[0])+1) * (abs(rect[3] - rect[1])+1);
            data[last + size] = rect;
            last = max_pick = last + size;
        }
    }
    
    vector<int> pick() 
    {
        long pick = rand() % (max_pick+1);
        auto& rect = data.lower_bound(pick)->second;
                
        int x = rand() % (rect[2] - rect[0] + 1) + rect[0];
        int y = rand() % (rect[3] - rect[1] + 1) + rect[1];
        
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
