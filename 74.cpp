class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.size() == 0)     
            return false;
        if (matrix[0].size() == 0)  
            return false;
        int m = matrix.size(), n = matrix[0].size();
        
        if(m == 0)
            return 0;
        int start = 0, end = m*n - 1;
        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if(matrix[mid/n][mid%n] == target)
            {
                return 1;
            }
            else if(matrix[mid/n][mid%n] < target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        if (matrix[start/n][start%n] == target) 
        {
            return 1;
        }
        if (matrix[end/n][end%n] == target) 
        {
            return 1;
        }
        return 0;
    }
};
