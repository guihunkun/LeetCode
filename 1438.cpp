class Solution 
{
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        int n = nums.size();
        int res = 1;
        int curr = 0;
        multiset<int> prev;
        prev.insert(nums[0]);
        for(int i = 1; i < n; ++i)
        {
            prev.insert(nums[i]);
            while(curr < i && abs(*prev.rbegin()-*prev.begin()) > limit) {
                prev.erase(nums[curr]);
                curr++;
            }
            res = max(res,(int)prev.size());
        } 
        return res;
    }
};


