class Solution 
{
public:
    int getTime(vector<int>& p1, vector<int>& p2)
    {
        int dx,dy;
        dx = fabs(p1[0] - p2[0]);
        dy = fabs(p1[1] - p2[1]);
        return max(dx, dy);
    }
    
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int ans = 0;
        for(int i = 1; i < points.size(); i++)
        {
            ans += getTime(points[i-1], points[i]);
        }
        return ans;
    }
};
