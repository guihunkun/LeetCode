class Solution 
{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int maxCandie = -1;
        for(auto can : candies)
        {
            maxCandie = max(maxCandie, can);
        }
        vector<bool> res(candies.size(), false);
        for(int i = 0; i < candies.size(); i++)
        {
            if(candies[i] + extraCandies >= maxCandie)
            {
                res[i] = true;
            }
        }
        return res;
    }
};
