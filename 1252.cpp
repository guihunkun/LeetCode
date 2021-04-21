/*
class Solution 
{
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) 
    {
        int res = 0;
        vector<vector<int> > record(n, vector<int>(m,0));
        int r,c;
        for(int i = 0; i < indices.size(); i++)
        {
            r = indices[i][0];
            c = indices[i][1];
            for(int j = 0; j < m; j++) {
                record[r][j]++;
            }
            for(int j = 0; j < n; j++) {
                record[j][c]++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(record[i][j]%2 == 1)
                    res++;
            }
        }
        return res;
    }
};
*/

/*
class Solution 
{
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) 
    {
        int res = 0;
        vector<int> row(n,0), col(m,0);
        int r,c;
        for(int i = 0; i < indices.size(); i++)
        {
            r = indices[i][0];
            c = indices[i][1];
            row[r]++;
            col[c]++;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((row[i] + col[j])%2 == 1)
                    res++;
            }
        }
        return res;
    }
};
*/

class Solution 
{
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) 
    {
        int res1 = 0, res2 = 0, res = 0;
        vector<int> row(n,0), col(m,0);
        int r,c;
        for(int i = 0; i < indices.size(); i++)
        {
            r = indices[i][0];
            c = indices[i][1];
            row[r]++;
            col[c]++;
        }
        for(int i = 0; i < n; i++)
        {
            if(row[i]%2 == 1)
                res1++;
        }
        for(int i = 0; i < m; i++)
        {
            if(col[i]%2 == 1)
                res2++;
        }
        res = res1*(m - res2) + (n - res1)*res2;
        return res;
    }
};
