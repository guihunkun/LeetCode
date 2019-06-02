/*
ass Solution 
{
public:
    int distributeCandies(vector<int>& candies)
    {
        sort(candies.begin(), candies.end());
        int count = 1;
        for(int i = 1; i < candies.size() && count < candies.size() / 2; i++)
            if(candies[i] > candies[i-1])
                count++;
        return count;
    }
};
*/
class Solution 
{
public:
    int distributeCandies(vector<int>& candies)
    {
        set<int> record;
        for(int candy : candies)
            record.insert(candy);
        return min(record.size(), candies.size() / 2);
    }
};
