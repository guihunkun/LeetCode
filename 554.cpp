class Solution 
{
public:
    int leastBricks(vector<vector<int>>& wall) 
    { 
        unordered_map<int, int> hash;       // {x, num}
        for (int i= 0; i < wall.size(); i++) 
        {
            int sum = 0;
            for (int j = 0;j < wall[i].size()-1; j++) 
            {
                sum += wall[i][j];
                ++hash[sum];
            }
        }
        int no_cross = 0;
        for (auto it = hash.begin(); it != hash.end(); ++it) 
        {
            no_cross = max(no_cross, it->second);
        }
        return wall.size() - no_cross;
    }
};
/*
用一个哈希表记录每个横坐标处砖头接头出现的次数。最后找出出现砖头接头最多的横坐标，即为需要切割的地方。
*/
