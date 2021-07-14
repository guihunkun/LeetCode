class Solution 
{
public:
/*
1. 对起点进行升序排序，如果起点相同，则对终点进行降序排序。
2. 初始化没有被覆盖的区间数：count=0。
3. 迭代排序后的区间并且比较终点大小。
   如果当前区间不被前一个区间覆盖 end > prev_end，则增加 count，指定当前区间为下一步的前一个区间。
   否则，当前区间被前一个区间覆盖，不做任何事情。
4. 返回 count。
*/
    static bool compare(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        } else {
            return a[0] < b[0];
        }
    }
   
    int removeCoveredIntervals(vector<vector<int> >& intervals) 
    {
        sort(intervals.begin(), intervals.end(), compare);
        int count = 0;
        int end, prev_end = 0;
        for(auto curr : intervals) 
        {
            end = curr[1];
            // if current interval is not covered
            // by the previous one
            if(prev_end < end) {
                ++count;
                prev_end = end;
            }
        }
        return count;
    }
};



