class Solution 
{
public:
    vector<int> divingBoard(int shorter, int longer, int k) 
    {
        vector<int> res;
        if(k == 0)
        {
            return res;
        }
        if(shorter == longer)
        {
            res.push_back(shorter*k);
            return res;
        }
        for(int i = 0; i <= k; i++)
        {
            res.push_back(shorter*(k-i) + longer*i);
        }
        return res;
    }
};
