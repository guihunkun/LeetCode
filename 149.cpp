/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/
//点到此点的斜率【用x:y的形式，最简形式】，然后用map存次数

class Solution {
public:
    int gcd(int a, int b) 
    {//最大公约数
        return b ? gcd(b, a%b) : a;
    }
    struct cmp
    {
        bool operator()(const Point &a, const Point &b)
        {
            return a.x < b.x || (a.x == b.x && a.y<b.y);
        }
    };

    int maxPoints(vector<Point>& points) 
    {
        if (points.empty()) 
            return 0;
        map<Point, int, cmp> A;
        int L = points.size(), ans = 1, n = 1;
        for (int i = 0; i < L; ++i) 
        {
            A.clear(); n = 1;
            for (int j =i + 1; j < L; ++j) 
            {
                if(j==i)
                    continue;
                int a = points[i].x - points[j].x, b = points[i].y - points[j].y;
                if (!(a | b)) 
                { 
                    ++n; continue; 
                }
                if (!a) 
                    ++A[Point(0, 1)];
                else if (!b) 
                    ++A[Point(1, 0)];
                else 
                {
                    int k = gcd(a, b);
                    ++A[Point(a / k, b / k)];
                }
            }
            ans = max(ans, n);
            for (auto &x : A)
                ans = max(ans, x.second + n);
        }
        return ans;

    }
};
