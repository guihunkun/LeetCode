class Solution 
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<pair<int, int>> data;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            data.emplace_back(nums[i], i);
        }
        sort(data.begin(), data.end());

        vector<int> ret(n, 0);
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (prev == -1 || data[i].first != data[i - 1].first) {
                prev = i;
            }
            ret[data[i].second] = prev;
        }
        return ret;
    }
};
