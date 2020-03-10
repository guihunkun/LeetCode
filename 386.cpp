class Solution 
{
public:
    void dfs(int k, int n, vector<int>& res) 
    {
        if(k > n) 
            return;
        if(k != 0) 
            res.push_back(k);
        for(int i = 0; i <= 9; ++i) 
        {
            if(10 * k + i > 0) 
            {
                dfs(10 * k + i, n, res);
            }
        }
    }
    vector<int> lexicalOrder(int n) 
    {
        vector<int> res;
        dfs(0, n, res);
        return res;
    }
};
