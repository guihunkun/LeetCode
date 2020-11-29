class Solution 
{
public:
    // 题意重述 : 给定一个数组，将其划分成 M 份，使得每份元素之和最大值最小，每份可以任意减去其中一个元素。
    // 可以借鉴LeetCode 410 ： 分割数组的最大值
    bool check(const vector<int>& time, int limit, int m)
    {
        int useDay = 1, totalTime = 0, maxtime = 0;
        for(int i = 0; i < time.size(); i++)
        {
            int nextTime = min(maxtime, time[i]);
            if(totalTime + nextTime <= limit) {
                totalTime += nextTime;
                maxtime = max(maxtime, time[i]);
            } else {
                useDay++;
                totalTime = 0;
                maxtime = time[i];
            }
        } 
        return useDay <= m;
    }
    int minTime(vector<int>& time, int m) 
    {
        int left = 0, right = 0, mid = 0;
        for(int i = 0; i < time.size(); i++)
        {
            right += time[i];
        }
        while(left < right)
        {
            mid = left + (right - left)/2;
            if(check(time, mid, m)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
