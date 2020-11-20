class Solution 
{
public:
    int minCount(vector<int>& coins) 
    {
        int res = 0;
        for(int i = 0; i < coins.size(); i++)
        {
            res += (coins[i]/2 + coins[i]%2);
        }
        return res;
    }
};
