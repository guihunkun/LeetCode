class Solution 
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) 
    {
        if (tx < sx || ty < sy) 
            return false;
        if (tx == sx && ty == sy) 
            return true;
        int nx, ny;
        if (tx > ty) {
            nx = (tx % ty) + (sx / ty) * ty;
            ny = ty;
        } else {
            nx = tx;
            ny = (ty % tx) + (sy / tx) * tx;
        }
        if (nx == tx && ny == ty) 
            return false;
        return reachingPoints(sx, sy, nx, ny);
    }
};
