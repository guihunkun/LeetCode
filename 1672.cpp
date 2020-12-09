class Solution 
{
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int res = 0;
        int money = 0;
        for(int i = 0; i < accounts.size(); i++)
        {
            money = 0;
            for(int j = 0; j < accounts[i].size(); j++)
            {
                money += accounts[i][j]; 
            }
            res = max(res, money);
        }
        return res;
    }
};
