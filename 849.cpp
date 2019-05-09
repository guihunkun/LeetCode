/*
class Solution 
{
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int left = -1, right = 0;
        int res = 0;
        for(int i = 0; i < seats.size(); i++)
        {
            if(seats[i] == 1)
                left = i;
            else
            {
                while(right < seats.size() && seats[right] == 0 || right < i)
                    right++;
                int l = left == -1 ? seats.size() : i - left;
                int r = right == seats.size() ? seats.size() : right - i;
                res = max(res, min(l, r));
            }
        }
        return res;
    }
};
*/

class Solution 
{
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        vector<int> left(seats.size(),seats.size()), right(seats.size(),seats.size());

        for (int i = 0; i < seats.size(); ++i) 
        {
            if (seats[i] == 1) 
                left[i] = 0;
            else if (i > 0) 
                left[i] = left[i-1] + 1;
        }

        for (int i = seats.size()-1; i >= 0; --i) 
        {
            if (seats[i] == 1) 
                right[i] = 0;
            else if (i < seats.size()-1) 
                right[i] = right[i+1] + 1;
        }
        
        int ans = 0;
        for (int i = 0; i < seats.size(); ++i)
            if (seats[i] == 0)
                ans = max(ans, min(left[i], right[i]));
        return ans;
    }
};
