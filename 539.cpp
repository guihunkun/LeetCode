class Solution 
{
public:
    const int DAY_MINUTE = 24 * 60;
    int time2int(const string& t) 
    {
        int hour = stoi(t.substr(0, 2));
        int minute = stoi(t.substr(3, 2));
        return hour * 60 + minute;
    }
    int findMinDifference(vector<string>& timePoints) 
    {
        int N = timePoints.size();
        vector<int> times(N, 0);
        for(int i = 0; i < N; ++i) 
        {
            times[i] = time2int(timePoints[i]);
        }
        sort(times.begin(), times.end());
        int res = min(times[N - 1] - times[0], times[0] + DAY_MINUTE - times[N - 1]);
        for (int i = 1; i < N; ++i) 
        {
            res = min(res, times[i] - times[i - 1]);
        }
        return res;
    }
};
