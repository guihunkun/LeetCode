class Solution 
{
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) 
    {
        int oldColor = image[sr][sc];   //记录旧坐标的像素
        if(image[sr][sc] == newColor) 
            return image; //颜色相同则无需修改
        image[sr][sc] = newColor; //染色
        vector<vector<int> > dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        for(int i = 0; i < 4; i ++) 
        {
            int x = sr + dirs[i][0];
            int y = sc + dirs[i][1];
            if(x >= 0 && y >= 0 && x < image.size() && y < image[0].size() && image[x][y] == oldColor)
                floodFill(image, x, y, newColor);
        }
        return image;
    }
};
