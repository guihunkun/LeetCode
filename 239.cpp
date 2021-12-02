class Solution 
{
public:
    void AddToDeque(deque<int> &d, int val) 
    {
        while (!d.empty() && d.back() < val)
            d.pop_back();
        d.push_back(val);
        return ;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if (nums.size() == 0)
            return {};
        //The maximum value of the current window will always be d.front().
        deque<int> d;
        for (int i = 0; i < k && i < nums.size(); ++i)
            AddToDeque(d, nums[i]);
        vector<int> result;
        for (int i = k; i < nums.size(); ++i) 
        {
            result.push_back(d[0]);
            if (d[0] == nums[i - k]) {
                d.pop_front();
            }
            AddToDeque(d, nums[i]);
        }
        result.push_back(d[0]);
        return result;
    }
};
