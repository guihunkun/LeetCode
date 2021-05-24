class Solution 
{
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        vector<pair<int,int>> diff(costs.size());
        for(int i = 0 ; i < costs.size() ;i++) {
            diff[i].second = i;
            diff[i].first = costs[i][0] - costs[i][1];            
        }
        sort(diff.begin(), diff.end());

        int finalCosts = 0;
        for(int i = 0 ; i < costs.size() / 2 ;i++)
            finalCosts += costs[diff[i].second][0];
        
        for(int i = costs.size() / 2 ; i < costs.size() ;i++)
            finalCosts += costs[diff[i].second][1];
        
        return finalCosts;
    }
};
