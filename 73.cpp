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
A���������飬bool[m] �� bool[n] �ֱ��ĳ�����㣬����ĳ�����㡣֮���������ֵ��ԭ������Ӧλ�����㡣����ռ�O(m + n)��

1. �ҵ�һ�����λ�ã����������е�������A�е����������ֵ��

2. ����1��λ�õ������к��е�ֵ�Ƿ����㽫������Ӧλ�����㡣

3. �ٰ�1��������λ�õ��к������㡣
*/
