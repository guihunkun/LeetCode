class Solution 
{
public:
    double Area(const vector<int> p1, const vector<int> p2, const vector<int> p3)
    {
        int dx1 = p2[0] - p1[0];
        int dx2 = p3[0] - p1[0];
        int dy1 = p2[1] - p1[1];
        int dy2 = p3[1] - p1[1];
        return abs(dx1 * dy2 - dx2 * dy1)*0.5;
    }
    double largestTriangleArea(vector<vector<int>>& points) 
    {
        double res(0.0);
        for(int i = 0; i < points.size(); ++i)
            for(int j = i + 1; j < points.size(); ++j)
                for(int k = j + 1; k < points.size(); ++k)
                    res = max(res, Area(points[i], points[j], points[k]));
        return res;
    }
};
