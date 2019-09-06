class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int s0 = 0;
        int s1 = -prices[0];
        int s2 = INT_MIN;
        for (int i = 1; i < prices.size(); i++){
            int pre0 = s0;
            int pre1 = s1;
            int pre2 = s2;
            s0 = max(pre0, pre2);
            s1 = max(pre0 - prices[i], pre1);
            s2 = pre1 + prices[i];
        }
        //最大利润不可能出现在buy而未sell的时候，所以不考虑s1
        return max(s0, s2);
    }
};
/*
s0[i] = max(s0[i - 1], s2[i - 1])
s1[i] = max(s0[i - 1] - prices[i], s1[i - 1])
s2[i] = s1[i - 1] + prices[i]
其中s0，s1，s2分别表示三种状态下的最大利润值。 
值得注意的是这里的s0，s1和s2不是单纯的buy，sell， rest，而应该是
s0 —— sell后rest或者rest后rest
s1 —— rest后的buy或者buy后的rest
s2 —— rest后的sell
*/



/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1)
        {
            return 0;
        }
        vector<vector<int> > dp;
        vector<int> profits(prices.size(), 0);
        for (int i = 0; i < prices.size(); i++)
        {
            dp.push_back(vector<int> ());
            for (int j = 0; j < prices.size(); j++)
            {
                dp[i].push_back(0);
            }
        }
        
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                dp[i][j] = prices[j] - prices[i];
                if (dp[i][j] < 0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        profits[1] = dp[0][1];
        
        for (int j = 1; j < prices.size(); j++)
        {
            if (j - 1 >= 0)
            {
                profits[j] = max(profits[j], profits[j - 1]);
            }
            if (j - 2 >= 0)
            {
                profits[j] = max(profits[j], profits[j - 2]);
            }
            for (int i = 0; i < j; i++)
            {
                profits[j] = max(profits[j], dp[i][j]);
                if (i - 2 >= 0)
                {
                    profits[j] = max(profits[j], dp[i][j] + profits[i - 2]);
                }
            }
        }
        return profits[prices.size() - 1];
    }
};
*/


/*
profits[j]表示在第j天的收益，dp[i][j]表示第i天买第j天卖的收益。

第j天能够有几种状态大家要清楚，第一种是第j天卖出股票，第二种是第j天买入股票，第三种第j天处于冻结期或者无任何操作。

第一种是第j天卖出股票，则profits[j] = max{profits[j]，dp[i][j]+profits[i-2]};

第二种是第j天买入股票，则profits[j] = max{profits[j]，profits[j-2]};

第三种第j天处于冻结期或者无任何操作，则profits[j] = max{profits[j]，profits[j-1]};
*/
