/*
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() <= 1)
            return 0;
        int valley = prices[0];
        int peak = prices[0];
        int i = 0;
        int maxprofit=0;
        while(i < prices.size()-1)
        {
            while(i < prices.size()-1 && prices[i] >= prices[i+1])
                i++;
            valley = prices[i];
            while(i < prices.size()-1 && prices[i] <= prices[i+1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;            
        }
        return maxprofit;
        
    }
};
*/


class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() <= 1)
            return 0;
        int maxprofit = 0;
        for(int i=1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i-1]) {
                maxprofit += prices[i] - prices[i-1];
            }
        }
        return maxprofit;
        
    }
};


