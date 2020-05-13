class Solution 
{
public:
    int triangleNumber(vector<int>& nums) 
    {
        if(nums.size() < 3) 
            return 0;
        sort(nums.begin(), nums.end(), greater<int>());
        int res = 0;
        int N = nums.size();
        for(int i = 0; i < N - 2; ++i) 
        {
            int l = i + 1;
            int r = N - 1;
            while(l < r) 
            {
                if(nums[l] + nums[r] <= nums[i]) 
                {
                    --r;
                } 
                else 
                {
                    res += r - l;
                    ++l;
                }
            }
        }
        return res;
    }
};

