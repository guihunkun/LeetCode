class Solution 
{
public:
    int maxSpacing(vector<int>& cuts, int right)
    {
        sort(cuts.begin(), cuts.end());
        int res = cuts[0] - 0;
        for(int i = 1; i < cuts.size(); i++)
        {
            res = max(res, cuts[i] - cuts[i-1]);
        }
        res = max(res, right - cuts[cuts.size()-1]);
        return res;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
    {
        int maxH = maxSpacing(horizontalCuts, h);
        int maxV = maxSpacing(verticalCuts, w);
        long long mod = (1e9 + 7);
        long long res = int64_t(maxH)*int64_t(maxV);
        return res%mod;
    }
};
