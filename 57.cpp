class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int l = 0, r = intervals.size() - 1, mid;
        // 判定特殊情况
        if(r < 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        // 二分查找
        while(l < r)
        {
            mid = (l + r) / 2;
            if(intervals[mid][0] < newInterval[0]) 
                l = mid + 1;
            else 
                r = mid;
        }
        // 判定特殊情况，这里是将区间整个插入到原有区间序列的头或尾
        int x = newInterval[0], y = newInterval[1];
        if(intervals[l][0] > y && (l == 0 || l > 0 && intervals[l - 1][1] < x) || intervals[l][1] < x)
        {
            intervals.push_back({x, y});
            sort(intervals.begin(),intervals.end());
            return intervals;
        }
        // 向右合并
        while(r < intervals.size() && intervals[r][0] <= y)
        {
            y = max(y, intervals[r][1]);
            x = min(x, intervals[r][0]);
            r ++;
        }
        //向左合并
        if(l > 0 && intervals[l - 1][1] >= x)
        {
            x = min(x, intervals[l - 1][0]);
            y = max(y, intervals[l - 1][1]);
            l --;
        }
        // 去除已经合并的区间
        intervals.erase(intervals.begin() + l, intervals.begin() + r);
        intervals.push_back({x, y});
        sort(intervals.begin(),intervals.end());
        return intervals;
    }
};
