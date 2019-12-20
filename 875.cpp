
class Solution 
{
public:
 
    bool canEat(vector<int>& piles, int speed, int H)
    {
        int res = 0;
        for(int p : piles)
        {
            res += (p - 1)/speed + 1;
        }
        return res <= H;
    }
    int minEatingSpeed(vector<int>& piles, int H) 
    {
        int low = 1, high = pow(10,9);
        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(!canEat(piles, mid, H))
            {
                low = mid + 1;
            }
            else
                high = mid;
        }
        return low;
    }
};
