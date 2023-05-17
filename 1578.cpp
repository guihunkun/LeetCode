class Solution 
{
public:
    int minCost(string s, vector<int>& cost) 
    {
        int n = s.size();
        int sum = 0;
        for(int i = 0; i < n-1; i++)
        {
            if(s[i] == s[i+1])
            {
                sum += min(cost[i], cost[i+1]); 
                if(cost[i] > cost[i+1])
                    swap(cost[i], cost[i+1]);
            }
        }
        return sum;
    }
};


