#define LL long long
class Solution 
{
public:
    int splitArray(vector<int>& nums, int m) 
    {
        LL l = 0, r = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) 
        {
            r += nums[i];
            if(l < nums[i]) 
            {
                l = nums[i];
            }
        }
        LL ans =  r;
        while(l <= r) 
        {
            LL mid = (l + r) >> 1;
            LL sum = 0;
            int cnt = 1;            
            for(int i = 0; i < n; i++) 
            {
                if(sum + nums[i] > mid) 
                {
                    cnt ++;
                    sum = nums[i];
                } 
                else 
                {
                    sum += nums[i];
                }
            }
            if(cnt <= m) 
            {
                ans = min(ans, mid);
                r = mid - 1;
            } 
            else 
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};
