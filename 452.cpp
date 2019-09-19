class Solution 
{
public:
    static bool compare(vector<int>& p1, vector<int>& p2)
    {
        return (p1[1] < p2[1]);
    }
    int findMinArrowShots(vector<vector<int>>& points) 
    {

        sort(points.begin(), points.end(), compare);
        int i = -1, ans = 0, j = 0, size = points.size();
        while(i < size && j < size) 
        {
            if(i < 0 || points[j][0] > points[i][1] )
            {
                i = j;
                ++ans;
            }
            ++j;
        }
        return ans;
    }
};
