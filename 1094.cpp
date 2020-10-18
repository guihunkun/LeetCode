class Solution 
{
public:
/*
1. 路程最大1000，所以建一个1000的数组表示在这个位置车上的人数
2. 根据trips的信息，如果是起始就加这么多人，如果到终点减这么多人
3. 遍历数组如果在那个位置车上的人多于最大值就返回false否则返回true
*/
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        int N = 1001;
        vector<int> rec(N, 0);
        int cur = 0;
        for(int i = 0; i < trips.size(); i++)
        {
            rec[trips[i][1]] += trips[i][0];
            rec[trips[i][2]] -= trips[i][0];
        }
        for(int i = 0; i < N; i++)
        {
            cur += rec[i];
            if(cur > capacity)
                return false;
        }
        return true;
    }
};
