class Solution 
{
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) 
    {
        if(ops.size() == 0)
            return m * n;
        int minR = ops[0][0], minC = ops[0][1];
        for(int i = 1; i < ops.size(); i++)
        {
            minR = min(minR, ops[i][0]);
            minC = min(minC, ops[i][1]);
        }
        return minR * minC;
    }
};
