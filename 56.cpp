class Solution 
{
public:
    static bool compare(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if(intervals.size() == 0)
            return intervals;
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int> > res;
        vector<int> tmp = intervals[0];
        for(int i =1; i < intervals.size(); i++)
        {
            if(tmp[1] < intervals[i][0])
            {
                res.push_back(tmp);
                tmp[0] = intervals[i][0];
                tmp[1] = intervals[i][1];
            }
            else
            {
                tmp[0] = min(tmp[0], intervals[i][0]);
                tmp[1] = max(tmp[1], intervals[i][1]);
            }
        }
        res.push_back(tmp);
        return res;
    }
};
