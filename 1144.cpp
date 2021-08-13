class Solution 
{
public:
    int movesToMakeZigzag(vector<int>& nums) 
    {
        if (nums.size() < 2) 
            return 0;
        int s1 = 0;
        int s2 = 0;
        int N = nums.size();
        for (int i = 0; i < N; ++i) 
        {
            int l = (i > 0) ? nums[i - 1] : INT_MAX;
            int r = (i < N - 1) ? nums[i + 1] : INT_MAX;
            if (i%2 == 1) {
                s1 += max(0, nums[i] - min(l, r) + 1);
            } else {
                s2 += max(0, nums[i] - min(l, r) + 1);
            }
        }
        return min(s1, s2);
    }
};
