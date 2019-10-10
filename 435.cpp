/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
bool compare(const Interval &a,const Interval &b)
{
    if(a.start!=b.start)
        return a.start<b.start;
    return a.end<b.end;
}
class Solution 
{
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) 
    {//动态规划
        if(intervals.size()==0)
            return 0;
        sort(intervals.begin(),intervals.end(),compare);
        
        vector<int> memo(intervals.size(),1);
        for(int i=0;i<intervals.size();i++)
            for(int j=0;j<i;j++)
                if(intervals[i].start>=intervals[j].end)
                    memo[i]=max(memo[i],1+memo[j]);
        int res=0;
        for(int i=0;i<memo.size();i++)
            res=max(res,memo[i]);
        return intervals.size()-res;
        
    }
};
*/


bool compare(const Interval &a,const Interval &b)
{
    if(a.end!=b.end)
        return a.end<b.end;
    return a.start<b.start;
}
class Solution 
{
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) 
    {//贪心算法
        if(intervals.size()==0)
            return 0;
        sort(intervals.begin(),intervals.end(),compare);
        int res=1;
        int pre=0;
        for(int i=1;i<intervals.size();i++)
            if(intervals[i].start>=intervals[pre].end)
            {
                res++;
                pre=i;
            }
        return intervals.size()-res;
        
    }
};







class Solution 
{
public:
    static bool compare(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] != b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {//贪心
        if(intervals.size() == 0)
            return 0;
        sort(intervals.begin(),intervals.end(),compare);
        int res=1;
        int pre=0;
        for(int i=1;i<intervals.size();i++)
            if(intervals[i][0] >= intervals[pre][1])
            {
                res++;
                pre=i;
            }
        return intervals.size()-res;
    }
};





/*
static bool compare(const vector<int>& a, const vector<int>& b)
{
    if(a[0] != b[0])
        return a[0] < b[0];
    return a[1] < b[1];
}
class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {//动态规划
        if(intervals.size()==0)
            return 0;
        sort(intervals.begin(),intervals.end(),compare);
        
        vector<int> memo(intervals.size(), 1);
        for(int i = 0; i < intervals.size(); i++)
            for(int j=0;j<i;j++)
                if(intervals[i][0] >= intervals[j][1])
                    memo[i]=max(memo[i], 1 + memo[j]);
        int res = 0;
        for(int i = 0; i < memo.size(); i++)
            res = max(res, memo[i]);
        return intervals.size()-res;
        
    }
};
*/
