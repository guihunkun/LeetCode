class Solution 
{
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        if(coordinates.size() == 2)
            return true;
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];
        for(int i = 0; i < coordinates.size() - 1; i++)
        {
            if(((coordinates[i+1][0] - coordinates[i][0])*dy) != ((coordinates[i+1][1] - coordinates[i][1])*dx))
                return false;
        }
        return true;
    }
};
