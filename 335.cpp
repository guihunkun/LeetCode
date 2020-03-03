class Solution 
{
public:
    bool isSelfCrossing(vector<int>& x) 
    {
        int n=x.size();
        if(n < 4)
            return false;
        for(int i = 3; i < n; ++i)
        {
            if(x[i-3] >= x[i-1] && x[i-2] <= x[i])
                return true;
            if(i > 3)
            {
                if(x[i-4]+x[i] >= x[i-2] && x[i-3] == x[i-1])
                    return true;
            }
            if(i>4)
            {
                if(x[i]+x[i-4]>=x[i-2] && x[i-2]>=x[i-4] && x[i-5]+x[i-1]>=x[i-3] && x[i-1]<=x[i-3])
                    return true;
            }
        }
        return false;
    }
};
