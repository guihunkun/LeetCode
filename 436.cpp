class Solution 
{
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        vector<int> ans(intervals.size());
        vector<vector<int>> intervals_copy = intervals;
        unordered_map<int, int> mp;
        for(int i = 0 ; i < intervals.size() ; ++i)
        {
            mp[intervals[i][0]] = i;
        }
        sort(intervals_copy.begin(), intervals_copy.end());
        vector<int> left;
        for(auto i : intervals_copy)
            left.push_back(i[0]);
        for(int i = 0 ; i < intervals.size() ; ++i)
        {
            int pos = lower_bound(left.begin(), left.end(), intervals[i][1]) - left.begin();
            if(pos < left.size())
                ans[i] = mp[left[pos]];
            else
                ans[i] = -1;
        }
        return ans;
    }
};
