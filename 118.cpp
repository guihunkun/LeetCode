class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> res;
        if(numRows==0) {
            return res;
        }
        if(numRows==1)
            return {{1}};
        res = {{1}};
        vector<int> curr_row;
        int r=1;
        while(r < numRows)
        {
            r++;
            curr_row.clear();
            curr_row.push_back(1);
            for(int i=1;i<r-1;i++)
                curr_row.push_back(res[r-2][i-1] + res[r-2][i]);
            curr_row.push_back(1);
            res.push_back(curr_row);
        }
        return res;
    }
};
