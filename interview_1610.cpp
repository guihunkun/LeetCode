class Solution 
{
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) 
    {
        vector<int> res(110, 0);
        int n = birth.size();
        //生于1908年、死于1909年的人应当被列入1908年和1909年的计数
        for(int i = 0; i < n; i++)
        {
            res[birth[i] - 1900] += 1;
            res[death[i] + 1 - 1900] -= 1;
        }
        int ans = 0;
        //年数的较小值
        int ret;
        for(int i = 1; i <= 101; i++)
        {
            res[i] += res[i-1];
            ans = max(ans, res[i]);
        }
        for(int i = 0; i <= 101; i++)
        {
            if(ans == res[i])
            {
                ret = i;
                break;
            }
        }
        return ret + 1900;
    }
};
