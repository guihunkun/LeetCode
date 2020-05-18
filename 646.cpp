
class Solution 
{
public:
    static bool cmp(const vector<int>& pa, const vector<int>& pb)
    {
        if(pa[1] == pb[1])
        {
            return pa[0] < pb[0];
        }
        else
            return pa[1] < pb[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        int res = 0;
        sort(pairs.begin(), pairs.end(), cmp);
        int min = INT_MIN;
        for(int i = 0; i < pairs.size(); i++)
        {
            if(pairs[i][0] > min)
            {
                res++;
                min = pairs[i][1];
            }
        }
        return res;
    }
};
