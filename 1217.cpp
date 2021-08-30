class Solution 
{
public:
    int minCostToMoveChips(vector<int>& chips) 
    {
        int even = 0, odd = 0;
        for(int chip : chips)
        {
            if((chip&1) == 0) {
                even++;
            } else {
                odd++;
            }
        }
        return min(odd, even);
    }
};




