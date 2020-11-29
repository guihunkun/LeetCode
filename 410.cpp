/*
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
*/

class Solution 
{
public:
    bool check(const vector<int>& nums, int maxsum, int m)
    {
        int sum = 0;
        int cnt = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(sum + nums[i] > maxsum) { 
                cnt++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return cnt <= m;
    }

    int splitArray(vector<int>& nums, int m) 
    {
        int left = 0, right = 0, mid = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            right += nums[i];
            if(left < nums[i]) {
                left = nums[i];
            }
        }
        while(left < right)
        {
            mid = left + (right - left)/2;
            if(check(nums, mid, m)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

