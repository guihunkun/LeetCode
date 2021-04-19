class SubrectangleQueries 
{
private:
    vector<vector<int>> rectangle;
    vector<vector<int>> rec;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle):rectangle(rectangle)
    {

    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) 
    {
        rec.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) 
    {
        for(int i = rec.size() - 1; i >= 0; i --)
        {
            if(rec[i][0] <= row && row <= rec[i][2] &&
               rec[i][1] <= col && col <= rec[i][3]) {
                return rec[i][4];
            }
        }
        return rectangle[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */

