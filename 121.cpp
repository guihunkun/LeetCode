class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() <= 1)
            return 0;
        int minprice = INT_MAX;
        int res=0;
        for(int i = 0;i < prices.size(); i++)
        {
            minprice = min(minprice, prices[i]);
            res = max(res, prices[i]-minprice);
        }
        return res;
    }
};
