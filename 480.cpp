class Solution 
{
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        vector<double> medians;
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        for(int i = k;; i++) 
        {

            // Push the current median
            medians.push_back(((double)(*mid) + *next(mid, k % 2 - 1)) * 0.5);
            // If all done, break
            if(i == nums.size())
                break;

            // Insert incoming element
            window.insert(nums[i]);
            if(nums[i] < *mid)
                mid--;                  // same as mid = prev(mid)

            // Remove outgoing element
            if(nums[i - k] <= *mid)
                mid++;                  // same as mid = next(mid)
            window.erase(window.lower_bound(nums[i - k]));
        }
        return medians;
    }
};
