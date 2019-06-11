class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 0 || n == 0)
            return ;
        int R = -1, C = -1;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 0)
                {
                    R = i;
                    C = j;
                    break;
                }
       if(R == -1)
           return ;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 0 && i != R && j != C)
                {
                    matrix[i][C] = 0;
                    matrix[R][j] = 0;
                }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(i != R && j != C)
                {
                    if(matrix[i][C] == 0)
                        matrix[i][j] = 0;
                    else if(matrix[R][j] == 0)
                        matrix[i][j] = 0;
                }
        for(int i = 0; i < n; i++)
            matrix[R][i] = 0;
        for(int i = 0; i < m; i++)
            matrix[i][C] = 0;
        return ;
        
    }
};


/*
A：两个数组，bool[m] 和 bool[n] 分别存某行有零，后者某列有零。之后根据数组值将原矩阵相应位置置零。额外空间O(m + n)。

1. 找到一个零的位置，把这行这列当做上述A中的两个数组存值。

2. 根据1的位置的所在行和列的值是否有零将矩阵相应位置置零。

3. 再把1中零所在位置的行和列置零。
*/
