/*
class Solution 
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) 
    {
        int m = nums.size(), n = nums[0].size();
        if(m*n != r*c) 
            return nums;
        vector<vector<int>> res(r, vector<int>(c));
        //变成r*c
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
            {
                int k = i*c+j; //原来数组的第k个数字
                res[i][j] = nums[k/n][k%n];
            }
        return res;
    }
};
*/
class Solution 
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) 
    {
        int m = nums.size(), n = nums[0].size();
        if(m*n != r*c) 
            return nums;
        vector<vector<int>> res(r, vector<int>(c));
        //变成r*c
        int count=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                res[count/c][count%c]=nums[i][j];
                count++;
            }
        return res;
    }
};
