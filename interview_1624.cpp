class Solution 
{
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) 
    {
        unordered_map<int, int> rec;
        vector<vector<int> > res;
        for(auto num : nums)
        {
            if(rec[target - num] > 0)
            {
                rec[target - num]--;
                res.push_back({num, target - num});
            }
            else
            {
                rec[num]++;
            }
        }
        return res;
    }
};
