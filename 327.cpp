class Solution 
{
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        // 计算前缀和
        vector<long> v = {0};
        for(int i = 0; i < nums.size(); ++i) 
        {
            v.emplace_back(v[i] + nums[i]);
        }
        
        return merge_sort(v, 0, v.size(), lower, upper);
    }
    
    int merge_sort(vector<long>& nums, int lo, int hi, int lower, int upper) 
    {
        if(hi - lo <= 1) 
            return 0;
        int mid = lo + (hi - lo >> 1);
        int count = merge_sort(nums, lo, mid, lower, upper) + merge_sort(nums, mid, hi, lower, upper);
        int right1 = mid, right2 = mid;
        for(int left = lo; left < mid; ++left) 
        {
            // 统计右侧-nums[left] < lower 的个数
            while(right1 != hi && nums[right1] - nums[left] < lower) 
                ++right1;
            // 统计右侧-nums[left] <= upper 的个数
            while(right2 != hi && nums[right2] - nums[left] <= upper) 
                ++right2;
            // 因此右侧-nums[left]的差在 [lower,upper] 的个数为：
            //count += (right2 - mid) - (right1 - mid); 可以简写为下面这样：
            count += right2 - right1;
        }
        inplace_merge(nums.begin() + lo, nums.begin() + mid, nums.begin() + hi);
        return count;
    }
};
